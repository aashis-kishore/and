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
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/include",
        "%{wks.location}/src/and/",
    }

    libdirs {
        "%{wks.location}/dev_dependencies/check/lib",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/lib",
        "%{wks.location}/dev_dependencies/viewmemutils/lib"
    }

    links {
        "check", "m", "rt",
        "bitvector",
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