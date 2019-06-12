workspace "datum_algum"
    configurations { "debug", "release" }

-- dev_support projects
dofile("./dev_support/print_messages/print_messages.lua")

-- dev_support projects tests
dofile("./tests/dev_support/test_print_messages/test_print_messages.lua")


-- src projects
dofile("./src/datastructures/stack/array/static_stack/static_stack.lua")
dofile("./src/datastructures/array/dynamic_array/dynamic_array.lua")                  -- dynamic_array

-- src projects tests
dofile("./tests/src/test_static_stack/test_static_stack.lua")
dofile("./tests/src/test_dynamic_array/test_dynamic_array.lua")                         -- test_dynamic_array


newaction {
    trigger = "clean",
    description = "remove all generated directories from the root directory",
    execute = function()
        os.rmdir("./obj")
        os.rmdir("./build")
    end,
}