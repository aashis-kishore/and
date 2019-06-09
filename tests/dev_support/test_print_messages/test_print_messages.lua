project "test_print_messages"
    kind "ConsoleApp"
    language "C"
    objdir "%{wks.location}/obj/tests/dev_support/%{prj.name}"
    targetdir "%{wks.location}/build/tests/dev_support/%{prj.name}/"

    defines {
        "DEBUG"
    }

    includedirs {
        "%{wks.location}/dev_dependencies/check/include",
        "%{wks.location}/dev_dependencies/print_messages/include"
    }

    libdirs {
        "%{wks.location}/dev_dependencies/check/lib",
    }

    links {
        "check", "m", "rt",
        "print_messages"
    }

    files {
        "*.c"
    }