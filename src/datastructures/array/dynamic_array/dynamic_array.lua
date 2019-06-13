project "dynamic_array"
    kind "StaticLib"
    language "C"
    objdir "%{wks.location}/obj/src/%{prj.name}/"
    targetdir "%{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/lib/"
    targetname "darray"

    includedirs {
        "%{wks.location}/src/and/",
    }

    filter "configurations:debug"
        defines {
            "DEBUG"
        }

        symbols "On"
    
    filter "configurations:release"
        defines {
            "NDEBUG"
        }

        optimize "On"

    filter {}

    files {
        "*.c"
    }

    buildoptions {
        "--std=c99",
        "-pedantic",
        "-Wall",
        "-Werror"
    }

    postbuildcommands {
        "{MKDIR} %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include",
        "{COPY} -u darray.h %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include" 
    }