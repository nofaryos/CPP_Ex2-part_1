#include "Board.hpp"
#include "doctest.h"
using namespace ariel;
using namespace std;



TEST_CASE("random cases"){
	Board board;
	board.post(0, 0, Direction::Horizontal, "abcd");
	CHECK(board.read(0,0, Direction::Horizontal, 4) == "abcd");
	board.post(0,1, Direction::Horizontal, "efg");
	CHECK(board.read(0,0, Direction::Horizontal, 4) == "aefg");
	board.post(0, 0, Direction::Vertical, "hefg");
	CHECK(board.read(0, 0,Direction::Horizontal, 4) == "hefg");
	CHECK(board.read(0, 0,Direction::Vertical, 4) == "hefg");	
}

TEST_CASE("empty messages"){
	Board board;
	CHECK(board.read(0,0, Direction::Horizontal, 3) == "___");
	CHECK(board.read(0,0, Direction::Vertical, 3) == "___");
	board.post(0,0, Direction::Horizontal, "a");
	CHECK(board.read(0,0, Direction::Vertical, 3) == "a__");
	CHECK(board.read(0,0, Direction::Horizontal, 3) == "a__");
	board.post(0, 2,  Direction::Horizontal, "a");
	CHECK(board.read(0,0, Direction::Horizontal, 3) == "a_a");
	board.post(2, 0,  Direction::Horizontal, "b");
	CHECK(board.read(0,0, Direction::Vertical, 3) == "a_b");
}

TEST_CASE("messages with spaces"){
	Board board;
	board.post(0,0, Direction::Horizontal, "   ");
	CHECK(board.read(0,0, Direction::Horizontal,3) == "   ");
	CHECK(board.read(0,0, Direction::Vertical,3) == " __");
	board.post(0,0, Direction::Horizontal, "a");
	CHECK(board.read(0,0, Direction::Horizontal,3) == "a  ");
	board.post(1,0, Direction::Vertical," b");
	CHECK(board.read(0,0, Direction::Vertical,3) == "a b");
}

TEST_CASE("messages with line drop"){
	Board board;
	board.post(0,0, Direction::Horizontal, "Line_1\nLine_2");
	CHECK(board.read(0, 0 , Direction::Horizontal,6) == "Line_1");
	CHECK(board.read(1, 0 , Direction::Horizontal,6) == "Line_2");
	CHECK(board.read(0, 0 , Direction::Vertical,6) == "LL____");
	CHECK(board.read(1, 0 , Direction::Vertical,6) == "L_____");
}

TEST_CASE("The last message is read"){
	Board board;
	board.post(0, 0, Direction::Horizontal, "abcd");
	CHECK(board.read(0, 0 , Direction::Horizontal,4) == "abcd");
	board.post(0, 0, Direction::Horizontal, "11");
	CHECK(board.read(0, 0 , Direction::Horizontal,4) == "11cd");
	board.post(0, 0, Direction::Horizontal, "2222");
	CHECK(board.read(0, 0 , Direction::Horizontal,4) == "2222");
}
	
	
		
		
		
	
	
	