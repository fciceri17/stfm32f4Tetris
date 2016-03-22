#ifndef GRID
#define GRID

namespace std{
	public class Grid{
		public: 
			void rotate();
			void translate(int direction);
			bool addBlock();
			void deleteRow();
			void updateGrid();
	}
}