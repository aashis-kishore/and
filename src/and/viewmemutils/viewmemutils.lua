project "viewmemutils"
    kind "StaticLib"
    language "C"
    objdir "%{wks.location}/obj/dev_utils/%{prj.name}/"
    targetdir "%{wks.location}/dev_dependencies/%{prj.name}/lib/"
    targetname "viewmemutils"

    defines {
        "DEBUG"
    }

    symbols "On"

    buildoptions {
        "--std=c99",
        "-Wall",
        "-Werror",
        "-g",
    }

    files {
        "*.c"
    }

    postbuildcommands {
        "{MKDIR} %{wks.location}/dev_dependencies/%{prj.name}/include",
        "{COPY} -u viewmemutils.h %{wks.location}/dev_dependencies/%{prj.name}/include" 
    }