project "dynamic_array"
    kind "StaticLib"
    language "C"
    objdir "%{wks.location}/obj/src/%{prj.name}/"
    targetdir "%{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/lib/"
    targetname "darray"

    includedirs {
        "%{wks.location}/src/and/",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/include/",
    }

    libdirs {
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/lib/",
    }

    links {
        "bitvector",
    }

    filter "configurations:debug"
        defines {
            "DEBUG"
        }

        symbols "On"

        buildoptions {
            "--std=c99",
            "-pedantic",
            "-Wall",
            "-Werror",
            "-g",
        }
    
    filter "configurations:release"
        defines {
            "NDEBUG"
        }

        optimize "On"

        buildoptions {
            "--std=c99",
            "-pedantic",
            "-Wall",
            "-Werror",
        }

    filter {}

    files {
        "*.c"
    }

    postbuildcommands {
        "{MKDIR} %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include",
        "{COPY} -u darray.h %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include" 
    }