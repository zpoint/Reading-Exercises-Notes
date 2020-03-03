package main
import qrcode "github.com/skip2/go-qrcode"

func main() {
	qrcode.WriteFile("我是大帅哥", qrcode.Medium, 256, "./golang_qrcode.png")
}
