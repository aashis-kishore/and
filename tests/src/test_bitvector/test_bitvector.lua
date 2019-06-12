project "test_bitvector"
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
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/include"
    }

    libdirs {
        "%{wks.location}/dev_dependencies/check/lib",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/lib"
    }

    links {
        "check", "m", "rt",
        "bitvector"
    }

    files {
        "*.c"
    }