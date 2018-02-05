pip install pybuilder
pyb --start-project

changed default action to analyze for time being

can't find unit tests:
change
    project.set_property("unittest_module_glob", "test_*")

can't import main project:

pyb -X for debug output
# use_plugin("python.unittest")
use_plugin('pypi:pybuilder_pytest')
    # project.set_property("dir_source_unittest_python", "test")
    project.set_property("dir_source_pytest_python", "test")

Command failed with arguments supplied in pytest plugin docs
    # extra arguments which will be passed to pytest
    # project.get_property("pytest_extra_args").append("-x")
