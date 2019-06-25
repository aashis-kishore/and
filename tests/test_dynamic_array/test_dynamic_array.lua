project "test_dynamic_array"
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
        "%{wks.location}/build/%{cfg.buildcfg}/lib/dynamic_array/include",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/include",
    }

    libdirs {
        "%{wks.location}/dev_dependencies/check/lib",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/dynamic_array/lib",
    }

    links {
        "check", "m", "rt",
        "dynamic_array",
        "bitvector",
    }

    files {
        "*.c"
    }