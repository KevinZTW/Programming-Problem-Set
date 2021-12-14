package main

import "fmt"

func permutate(n int) {
	var picked = make([]int, n)
	var data = make([]int, n)
	permuteHelper(n, 0, picked, data)
}

func permuteHelper(n, level int, picked, data []int) {

	if level == n {

		fmt.Println(data)
		return
	}
	for i := 0; i < n; i++ {
		if picked[i] == 1 {
			continue
		}

		picked[i] = 1
		data[level] = i + 1
		permuteHelper(n, level+1, picked, data)
		picked[i] = 0
	}
}

func main() {
	permutate(5)
}
