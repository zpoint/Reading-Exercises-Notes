package main

import (
	qrcode "github.com/skip2/go-qrcode"
	"image/color"
	"log"
)

func main() {
	qr,err:=qrcode.New("我是大帅哥2",qrcode.Medium)
	if err != nil {
		log.Fatal(err)
	} else {
		qr.BackgroundColor = color.RGBA{50,205,50,255}
		qr.ForegroundColor = color.White
		qr.WriteFile(256,"./golang_qrcode.png")
	}
}