project "test_static_array"
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
        "%{wks.location}/build/%{cfg.buildcfg}/lib/static_array/include",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/include",
        "%{wks.location}/src/and/"
    }

    libdirs {
        "%{wks.location}/dev_dependencies/check/lib",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/static_array/lib"
    }

    links {
        "check", "m", "rt",
        "static_array",
        "bitvector",
    }

    files {
        "*.c"
    }