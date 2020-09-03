package main

/* buggy
 to be continued 
 */
import "fmt"

func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

var LEFT = true
var RIGHT = false

type Result struct {
	Val int
	LeftVal int
	WinDirection bool
}

func PredictTheWinner(nums []int) bool {
	numSize := len(nums)
	if numSize <= 2 {
		return true
	}
	var matrix [][]Result = make([][]Result, numSize)
	for index, _ := range matrix {
		matrix[index] = make([]Result, numSize)
		matrix[index][index] = Result{nums[index], 0, LEFT}
	}
	for size := 2; size <= numSize; size++ {
		for beginIndex := 0; beginIndex <= numSize - size; beginIndex++ {
			endIndex := beginIndex + size - 1
			if endIndex - beginIndex <= 1 {
				if matrix[beginIndex][beginIndex].Val > matrix[endIndex][endIndex].Val {
					matrix[beginIndex][endIndex] = Result{nums[beginIndex], nums[endIndex], LEFT}
				} else {
					matrix[beginIndex][endIndex] = Result{nums[endIndex], nums[beginIndex], RIGHT}
				}
			} else {
				LeftPick := nums[beginIndex] + matrix[beginIndex+1][endIndex].LeftVal
				RightPick := nums[endIndex] + matrix[beginIndex][endIndex-1].LeftVal
				if LeftPick > RightPick {
					matrix[beginIndex][endIndex] = Result{LeftPick, matrix[beginIndex+1][endIndex].Val, LEFT}
				} else {
					matrix[beginIndex][endIndex] = Result{RightPick, matrix[beginIndex][endIndex-1].Val, RIGHT}
				}
			}
		}
	}
	return matrix[0][numSize-1].Val > matrix[0][numSize-1].LeftVal || matrix[0][numSize-2].Val > matrix[0][numSize-2].LeftVal
}

func main() {
	fmt.Println(PredictTheWinner([]int{1, 5, 2}))
}
