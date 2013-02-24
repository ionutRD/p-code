import os
import sys
import unittest

TEST_FILE_ERROR_MSG = "An error occurred while trying to \
                       read test files: {0}, {1}"
OS_ERROR_MSG = "An error occurred while trying to execute \
                the following command: {0}"

class TestSimpleSinglyLinkedListOperations(unittest.TestCase):
  def setUp(self):
    self.in_content = None
    self.ref_content = None

  def test_add_back__1(self):
    " Test add_back 1 "
    try:
      test_file_name = "test/test1"
      test_ref_name = "{0}.ref".format(test_file_name)
      test_result_name = "{0}.result".format(test_file_name)
      cmd = "./exec < {0} > {1}".format(test_file_name, \
                                        test_result_name)
      os.system(cmd)
      test_result = open(test_result_name, "r")
      test_ref = open(test_ref_name, "r")
      self.result_content = test_result.readlines()
      self.ref_content = test_ref.readlines()
      self.assertEqual(self.result_content, self.ref_content)
      test_result.close()
      test_ref.close()
      os.remove(test_result_name)
    except IOError:
      sys.stderr.write(TEST_FILE_ERROR_MSG.format(test_file_name,\
                                                  test_ref_name))
    except OSError:
      sys.stderr.write(OS_ERROR_MSG.format(cmd))

  def test_add_back__2(self):
    " Test add_back 2 "
    try:
      test_file_name = "test/test2"
      test_ref_name = "{0}.ref".format(test_file_name)
      test_result_name = "{0}.result".format(test_file_name)
      cmd = "./exec < {0} > {1}".format(test_file_name, \
                                        test_result_name)
      os.system(cmd)
      test_result = open(test_result_name, "r")
      test_ref = open(test_ref_name, "r")
      self.result_content = test_result.readlines()
      self.ref_content = test_ref.readlines()
      self.assertEqual(self.result_content, self.ref_content)
      test_result.close()
      test_ref.close()
      os.remove(test_result_name)
    except IOError:
      sys.stderr.write(TEST_FILE_ERROR_MSG.format(test_file_name,\
                                                  test_ref_name))
    except OSError:
      sys.stderr.write(OS_ERROR_MSG.format(cmd))

if __name__ == "__main__":
  suite = unittest.TestLoader().\
  loadTestsFromTestCase(TestSimpleSinglyLinkedListOperations)
  unittest.TextTestRunner(verbosity = 3).run(suite)
