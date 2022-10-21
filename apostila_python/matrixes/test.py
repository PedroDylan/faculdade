import unittest
from op_matrix import op_matrix 

class TestSum(unittest.TestCase):
    
    def test_result_sum(self):
        mt1 = op_matrix.Matrix([1,2,3],[1,2,3],[1,2,3])
        mt2 = op_matrix.Matrix([2,3,4],[2,3,4],[2,3,4])
        mt3 = op_matrix.Matrix([3,5,7],[3,5,7],[3,5,7])
        result = mt1.add_mat(mt2)
        self.assertEqual(result,mt3)

    def test_result_mult(self):
        mt1 = op_matrix.Matrix([1,2,3],[1,2,3],[1,2,3])
        mt2 = op_matrix.Matrix([2,3,4],[2,3,4],[2,3,4])
        mt3 = op_matrix.Matrix([20,20,20],[20,20,20],[20,20,20])
        result = mt1.mult_mat(mt2)
        self.assertEqual(result,mt3)

if __name__ == "__main__":
    unittest.main()