import os
import sys
import unittest

TEST_FILE_ERROR_MSG = "An error occurred while trying to \
                       read test files: {0}, {1}"
OS_ERROR_MSG = "An error occurred while trying to execute \
                the following command: {0}"

def unittest_eq(fin, assert_fun):
  " Execute one unit test "
  try:
    test_file_name = fin
    test_ref_name = "{0}.ref".format(test_file_name)
    test_result_name = "{0}.result".format(test_file_name)
    cmd = "./exec < {0} > {1}".format(test_file_name, \
                                      test_result_name)
    os.system(cmd)
    test_result = open(test_result_name, "r")
    test_ref = open(test_ref_name, "r")
    result_content = test_result.readlines()
    ref_content = test_ref.readlines()
    assert_fun(result_content, ref_content)
    test_result.close()
    test_ref.close()
    os.remove(test_result_name)
  except IOError:
    sys.stderr.write(TEST_FILE_ERROR_MSG.format(test_file_name,\
                                                test_ref_name))
  except OSError:
    sys.stderr.write(OS_ERROR_MSG.format(cmd))


class TestSimpleSinglyLinkedListOperations(unittest.TestCase):
  " Simple operations test suite "

  def test_add_back__1(self):
    " Test add_back 1 "
    unittest_eq("test/test1", self.assertEqual)

  def test_add_back__2(self):
    " Test add_back 2 "
    unittest_eq("test/test2", self.assertEqual)

if __name__ == "__main__":
  suite = unittest.TestLoader().\
  loadTestsFromTestCase(TestSimpleSinglyLinkedListOperations)
  unittest.TextTestRunner(verbosity = 3).run(suite)
