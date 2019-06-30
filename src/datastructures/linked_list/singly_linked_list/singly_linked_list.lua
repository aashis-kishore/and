project "singly_linked_list"
    kind "StaticLib"
    language "C"
    objdir "%{wks.location}/obj/src/%{prj.name}/"
    targetdir "%{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/lib/"
    targetname "sllist"

    includedirs {
        "%{wks.location}/src/and/",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/singly_linked_list/include/",
    }

    libdirs {
        "%{wks.location}/build/%{cfg.buildcfg}/lib/singly_linked_list/lib/",
    }

    links {
        "singly_linked_list",
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
    "{COPY} -u sllist.h %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include" 
}