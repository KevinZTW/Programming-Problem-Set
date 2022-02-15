package main

import "fmt"

func generateParenthesisHelper(cur *string, left int, store *[]string) {

	if left > 0 {
		//two option
		*cur += "("
		generateParenthesisHelper(cur, left-1, store)
		*cur += ")"
		generateParenthesisHelper(cur, left-1, store)

	} else {
		*cur += "()"
		fmt.Println(store)
		fmt.Println(*cur)
		*store = append(*store, *cur)
		fmt.Println(store)
	}

}

func generateParenthesis(n int) []string {
	var store []string
	cur := ""
	generateParenthesisHelper(&cur, n, &store)
	fmt.Print("ans:")
	fmt.Println(store)
	return store
}

func main() {
	ans := generateParenthesis(3)
	fmt.Println(ans)
}
