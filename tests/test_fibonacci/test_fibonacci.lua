project "test_fibonacci"
    kind "ConsoleApp"
    language "C"
    objdir "%{wks.location}/obj/tests/src/%{prj.name}"
    targetdir "%{wks.location}/build/%{cfg.buildcfg}/tests/%{prj.name}"

    defines {
        "DEBUG"
    }

    symbols "On"

    includedirs {
        "%{wks.location}/dev_dependencies/check/include",
        "%{wks.location}/src/and/",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/fibonacci/include",
    }

    libdirs {
        "%{wks.location}/dev_dependencies/check/lib",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/fibonacci/lib",
    }

    links {
        "check", "m", "rt",
        "fibonacci",
    }

    files {
        "*.c"
    }