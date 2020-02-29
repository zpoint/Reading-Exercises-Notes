package main
import (
	"fmt"
	"log"
	"net"
	"os"
)
func main() {
	if len(os.Args) != 2 {
		log.Fatalf("Usage: %s host:port", os.Args[0])
	}
	service := os.Args[1]
	tcpAddr, err := net.ResolveTCPAddr("tcp4", service)
	if err != nil {
		log.Fatal(err)
	}
	conn, err := net.DialTCP("tcp4", nil, tcpAddr)
	if err != nil {
		log.Fatal(err)
	}
	n, err := conn.Write([]byte("HEAD / HTTP/1.1\r\n\r\n"))
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%d\n", n)
	// log.Fatal(n)
	var bPtr [53]byte
	fmt.Printf("%T\n", bPtr)
	for {
		n, err = conn.Read(bPtr[0:])
		fmt.Printf("n: %d\n", n)
		fmt.Printf("bPtr[:%d]: %s\n", n, bPtr[:n])

		if err != nil {
			log.Fatal(err)
		}

	}

}