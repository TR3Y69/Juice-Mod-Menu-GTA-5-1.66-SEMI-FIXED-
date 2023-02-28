#include "Logger.hpp"

namespace Big
{
	Logger::Logger()
	{
		try
		{
			m_FilePath.append(std::getenv("appdata"));
			m_FilePath.append(BIGBASE_NAME);
			if (!fs::exists(m_FilePath))
				fs::create_directory(m_FilePath);
			m_FilePath.append("Juice.log");
		}
		catch (fs::filesystem_error const&)
		{
		}


		if (!AttachConsole(GetCurrentProcessId()))
			AllocConsole();
		SetConsoleTitleW(BIGBASE_WIDE(BIGBASE_NAME));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);

		m_Console.open("CONOUT$");
		m_Input.open("CONIN$");
		m_File.open(m_FilePath, std::ios_base::out | std::ios_base::app);
	}

	Logger::~Logger() noexcept
	{
		FreeConsole();
	}

	void Logger::Info(const char* format, ...)
	{
		
		std::va_list args{};
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); Log("Pattern", format, args);
		va_end(args);
	}

	void Logger::Hooks(const char* format, ...)
	{

		std::va_list args{};
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); Log("Info", format, args);
		va_end(args);
	}

	void Logger::Error(const char* format, ...)
	{
      std::va_list args{};
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE); Log("Succes", format, args);
		va_end(args);
	}
	void Logger::Infos(const char* format, ...)
	{
		std::va_list args{};
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); Log("OnlineGame", format, args);
		va_end(args);
	}
	void Logger::Hooking(const char* format, ...)
	{
		std::va_list args{};
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); Log("Hooking", format, args);
		va_end(args);
	}
	void Logger::notify(const char* format, ...)
	{
		std::va_list args{};
		va_start(args, format);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); Log("Notify", format, args);
		va_end(args);
	}

	void Logger::Log(const char* type, const char* format, std::va_list args)
	{
		std::lock_guard lock(m_Mutex);

		auto time = std::time(nullptr);
		auto tm = std::localtime(&time);
		char prefix[64] = {};
		std::snprintf(prefix, sizeof(prefix) - 1, "| Juice | %02d:%02d:%02d | %s | ", tm->tm_hour, tm->tm_min, tm->tm_sec, type);

		std::size_t messageLength = std::vsnprintf(nullptr, 0, format, args) + 1;
		auto messageBuffer = std::make_unique<char[]>(messageLength);

		std::uninitialized_fill_n(messageBuffer.get(), messageLength, '\0');
		std::vsnprintf(messageBuffer.get(), messageLength, format, args);

		m_File << prefix << messageBuffer.get() << std::endl;
		m_Console << prefix << messageBuffer.get() << std::endl;

		m_Messages.push_back(std::move(messageBuffer));
	}

	std::mutex& Logger::GetMutex()
	{
		return m_Mutex;
	}

	std::pair<std::unique_ptr<char[]>*, std::size_t> Logger::GetMessages()
	{
		return std::make_pair(m_Messages.data(), m_Messages.size());
	}

	std::istream& Logger::GetInput()
	{
		return m_Input;
	}
}
