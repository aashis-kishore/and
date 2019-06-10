workspace "datum_algum"
    configurations { "debug", "release" }

-- dev_support projects
dofile("./dev_support/print_messages/print_messages.lua")

-- dev_support projects tests
dofile("./tests/dev_support/test_print_messages/test_print_messages.lua")


-- src projects
dofile("./src/datastructures/stack/c/array/static_stack/static_stack.lua")

-- src projects tests
dofile("./tests/src/test_static_stack/test_static_stack.lua")


newaction {
    trigger = "clean",
    description = "remove all generated directories from the root directory",
    execute = function()
        os.rmdir("./obj")
        os.rmdir("./build")
    end,
}