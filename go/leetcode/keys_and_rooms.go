package main

import (
	"fmt"
	"math"
	"reflect"
)

var AllSetBitMap uint64 = math.MaxUint64

type bitSet struct {
	bitMap []uint64
	bitSize int
	mask uint64
}

func (b *bitSet) Has(index int) bool {
	location := index + 1
	bitMapIndex := int(math.Ceil(float64(location / 64.0)))
	return (b.bitMap[bitMapIndex] & (1 << index)) > 0
}

func (b *bitSet) Add(index int) bool {
	location := index + 1
	bitMapIndex := int(math.Ceil(float64(location / 64.0)))
	b.bitMap[bitMapIndex] |= 1 << index
	return true
}

func (b *bitSet) AllSet() bool {
	for _, eachBitSet := range b.bitMap[1:] {
		if eachBitSet != AllSetBitMap {
			return false
		}
	}
	if b.bitMap[0] | b.mask != AllSetBitMap {
		return false
	}
	return true
}

func NewBitSet(len int) *bitSet {
	arraySize := int(math.Ceil(float64(len) / 64))
	rest := len % 64
	var mask uint64 = 0
	if rest > 0 {
		mask = (uint64(1) << rest) - 1
		mask = ^mask
	} else {
		mask = 0
	}
	bitMap := make([]uint64, arraySize)
	b := bitSet{bitMap: bitMap, bitSize: len, mask: mask}
	return &b
}


func canVisitAllRooms(rooms [][]int) bool {
	if len(rooms) < 1 {
		return true
	}
	roomReachedBitSet := NewBitSet(len(rooms))
	roomVisitedBitSet := NewBitSet(len(rooms))
	roomIndex := rooms[0][0:len(rooms[0]):len(rooms[0])]
	roomVisitedBitSet.Add(0)
	roomReachedBitSet.Add(0)
	for _, key := range rooms[0] {
		roomReachedBitSet.Add(key)
	}

	for len(roomIndex) > 0 {
		nextRoomIndex := roomIndex[len(roomIndex)-1]
		roomIndex = roomIndex[:len(roomIndex)-1]
		roomVisitedBitSet.Add(nextRoomIndex)
		// visit next room
		for _, key := range rooms[nextRoomIndex] {
			if !roomReachedBitSet.Has(key) {
				roomReachedBitSet.Add(key)
			}
			if !roomVisitedBitSet.Has(key) {
				roomIndex = append(roomIndex, key)
				roomVisitedBitSet.Add(key)
			}
		}
	}
	return roomReachedBitSet.AllSet()
}

func main() {
	fmt.Printf("%+v\n", []int{1, 2})
	fmt.Println("4 / 64.0: ", 4 / 64.0, math.Ceil(4 / 64.0))
	v := []int{1, 2}
	fmt.Println(reflect.TypeOf(v))
	fmt.Println(canVisitAllRooms([][]int{[]int{1, 3}, []int{3, 0, 1}, []int{2}, []int{0}}))
	fmt.Println(canVisitAllRooms([][]int{[]int{1}, []int{2}, []int{3}, []int{}}))
}
