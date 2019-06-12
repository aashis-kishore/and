project "test_static_stack"
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
        "%{wks.location}/build/%{cfg.buildcfg}/lib/static_stack/include",
        "%{wks.location}/src/and/"
    }

    libdirs {
        "%{wks.location}/dev_dependencies/check/lib",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/static_stack/lib"
    }

    links {
        "check", "m", "rt",
        "static_stack"
    }

    files {
        "*.c"
    }