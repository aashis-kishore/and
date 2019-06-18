project "test_viewmemutils"
    kind "ConsoleApp"
    language "C"
    objdir "%{wks.location}/obj/tests/dev_utils/%{prj.name}"
    targetdir "%{wks.location}/build/%{cfg.buildcfg}/tests/%{prj.name}"

    defines {
        "DEBUG"
    }

    symbols "On"

    includedirs {
        -- "%{wks.location}/dev_dependencies/check/include",
        "%{wks.location}/dev_dependencies/viewmemutils/include",
        -- "%{wks.location}/src/and/",
    }

    libdirs {
        -- "%{wks.location}/dev_dependencies/check/lib",
        "%{wks.location}/dev_dependencies/viewmemutils/include"
    }

    links {
        -- "check", "m", "rt",
        "viewmemutils"
    }

    files {
        "*.c"
    }

    buildoptions {
        "--std=c99",
        "-pedantic",
        "-Wall",
        "-Werror",
        "-g"
    }