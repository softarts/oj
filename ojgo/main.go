package main
import (
    "fmt"
    "go/ast"
    "go/parser"
    "go/token"
    "os"
	
)

const subPackage = "leetcode"

func main() {
    set := token.NewFileSet()
    packs, err := parser.ParseDir(set, subPackage, nil, 0)
    if err != nil {
        fmt.Println("Failed to parse package:", err)
        os.Exit(1)
    }

    funcs := []*ast.FuncDecl{}
    for _, pack := range packs {
        for _, f := range pack.Files {
            for _, d := range f.Decls {
                if fn, isFn := d.(*ast.FuncDecl); isFn {
                    funcs = append(funcs, fn)
					fmt.Println(fn)
                }
            }
        }
    }

    fmt.Printf("all funcs: %+v\n", funcs)
}