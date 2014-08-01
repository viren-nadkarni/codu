   1.
      #include<stdio.h>
   2.
      #include<iostream.h>
   3.
      #include<conio.h>
   4.
      #include<alloc.h>
   5.
      #include<math.h>
   6.
      #include<stdlib.h>
   7.
      #include<DOS.h>
   8.
      #include<graphics.h>
   9.
       
  10.
      #define SQSIZE 30
  11.
      #define DELAY 500
  12.
      long count = 0;
  13.
      void initialize_graphics(int&, int&);
  14.
      int** MakeChessBoard(int);
  15.
      int PlaceQueens(int**, int, int);
  16.
      int CheckKill(int**, int, int, int);
  17.
      void CreateChessBoard(int**, int);
  18.
      void DeleteChessBoard(int**, int);
  19.
      void PlaceQueen(int, int);
  20.
      void RemoveQueen(int, int) ;
  21.
      void HomeQueen(int);
  22.
       
  23.
      int max_x, max_y;
  24.
       
  25.
      void main()
  26.
      {
  27.
      int** chessboard;
  28.
      int i, j, size;
  29.
      cout << "N-Queen Problem" << endl;
  30.
      cout << "Press any Key to continue...";
  31.
      getch();
  32.
      do
  33.
      {
  34.
      clrscr();
  35.
      printf("Enter Size of chessBoard[Number of rows or columns ie. N]:");
  36.
      scanf("%d", &size);
  37.
      if (size < 4)
  38.
      {
  39.
      printf("\nThere is NO solution for N<4");
  40.
      getch();
  41.
      }
  42.
      }
  43.
      while (size < 4);
  44.
      chessboard = MakeChessBoard(size);
  45.
      initialize_graphics(max_x, max_y);
  46.
      CreateChessBoard(chessboard, size);
  47.
      PlaceQueens(chessboard, size, 0);
  48.
      getch();
  49.
      DeleteChessBoard(chessboard, size);
  50.
      }
  51.
      int** MakeChessBoard(int size)
  52.
      {
  53.
      int** chessboard;
  54.
      int i, j;
  55.
      /*Allocate Double Dimention Array*/
  56.
      chessboard = (int * *) malloc(sizeof(int) * size);
  57.
      for (i = 0; i < size; i++)
  58.
      chessboard[i] = (int *) malloc(sizeof(int) * size);
  59.
      /*Initialize Double Dimention Array*/
  60.
      for (i = 0; i < size; i++)
  61.
      for (j = 0; j < size; j++)
  62.
      chessboard[i][j] = 0;
  63.
      return chessboard;
  64.
      }
  65.
      int PlaceQueens(int** chessboard, int size, int level)
  66.
      {
  67.
      count++;
  68.
      int Q_placed = 0; /*
  69.
      Q_placed is a flag reflecting that whether a Queen
  70.
      is placed on the current level or not.
  71.
      This value is returned to preceeding levels.
  72.
      */
  73.
      int QNextLevel; /*
  74.
      QNextLevel is a flag reflecting that whether a Queen
  75.
      is placed on the next level or not.
  76.
      During recurssion this Flag will allow recurssion
  77.
      */
  78.
       
  79.
      int flag; /*
  80.
      Determines whether a Queen can be placed at current
  81.
      position or not.
  82.
      */
  83.
      int i;
  84.
      for (i = 0; i < size; i++)
  85.
      {
  86.
      /*Breaks the loops after all the Queens have been placed*/
  87.
      if (Q_placed == 1)
  88.
      break;
  89.
      /*Check whether Queen can be placed or not*/
  90.
      flag = CheckKill(chessboard, size, level, i);
  91.
      /*If Queen can be placed*/
  92.
      if (flag == 0)
  93.
      {
  94.
      /*Queen Placed. This will be changed if Next level Queen is
  95.
      not placed succesfully*/
  96.
      Q_placed = 1;
  97.
      /*Queen Placed. */
  98.
      chessboard[level][i] = 1;
  99.
      PlaceQueen(level, i);
 100.
      /*Check for Last level*/
 101.
      if (level == size - 1)
 102.
      ;
 103.
      else /*Place a next level Queen*/
 104.
      {
 105.
      QNextLevel = PlaceQueens(chessboard, size, level + 1);
 106.
      /*If next level Queen is not Placed.*/
 107.
      if (QNextLevel == 0)
 108.
      {
 109.
      /*Mark this level Queen as Not Placed*/
 110.
      Q_placed = 0;
 111.
      chessboard[level][i] = 0;
 112.
      RemoveQueen(level, i);
 113.
      if (i == size - 1)
 114.
      HomeQueen(level);
 115.
      }
 116.
      }
 117.
      }
 118.
      else if (flag == 1)
 119.
      {
 120.
      PlaceQueen(level, i);
 121.
      RemoveQueen(level, i);
 122.
      if (i == size - 1)
 123.
      HomeQueen(level);
 124.
      }
 125.
      }
 126.
      return Q_placed;
 127.
      }
 128.
      int CheckKill(int** chessboard, int size, int row, int column)
 129.
      {
 130.
      int i, j;
 131.
      for (i = 0; i < row; i++)/*ROW Loop: Only From 0 to (Current Level - 1) */
 132.
      for (j = 0; j < size; j++)/*COLUMN Loop:From 0 to ChessBoardsize */
 133.
      if (chessboard[i][j] == 1)/*If there is a Queen*/
 134.
      if (j == column)
 135.
      return 1; /*If Queen is in the same column*/
 136.
      else if (abs(i - row) == abs(j - column))
 137.
      return 1;/*If it is Diagonal*/
 138.
      return 0;
 139.
      }
 140.
      void CreateChessBoard(int** chessboard, int size)
 141.
      {
 142.
      setfillstyle(SOLID_FILL, LIGHTBLUE);
 143.
      setcolor(RED);
 144.
      bar(0, 0, max_x, max_y);
 145.
      for (int i = 0; i < size; i++)
 146.
      {
 147.
      for (int j = 1; j <= size; j++)
 148.
      {
 149.
      if (i % 2 == j % 2)
 150.
      setfillstyle(SOLID_FILL, WHITE);
 151.
      else
 152.
      setfillstyle(SOLID_FILL, YELLOW);
 153.
      bar(j * SQSIZE, i * SQSIZE, (j + 1) * SQSIZE, (i + 1) * SQSIZE);
 154.
      }
 155.
      }
 156.
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
 157.
      setcolor(WHITE);
 158.
      outtextxy(max_x - 300, max_y - 50, "N Queen -PCD-");
 159.
      setcolor(RED);
 160.
      setlinestyle(SOLID_LINE, 0, 1);
 161.
      for (int p = 0; p <= max_x; p += SQSIZE)
 162.
      line(p, 0, p, max_y);
 163.
      for (p = 0; p <= max_x; p += SQSIZE)
 164.
      line(0, p, max_x, p);
 165.
      }
 166.
      void DeleteChessBoard(int** chessboard, int size)
 167.
      {
 168.
      int i;
 169.
      for (i = 0; i < size; i++)
 170.
      free(chessboard[i]);
 171.
      free(chessboard);
 172.
      }
 173.
      void initialize_graphics(int& max_x, int& max_y)
 174.
      {
 175.
      /*
 176.
      initialize_graphics() function initializes the graphic enviroment.
 177.
      */
 178.
      int gdriver = DETECT, gmode, errorcode;
 179.
       
 180.
      initgraph(&gdriver, &gmode, NULL);
 181.
       
 182.
      /* read result of initialization */
 183.
      errorcode = graphresult();
 184.
      if (errorcode != grOk) /* an error occurred */
 185.
      {
 186.
      cout << "Graphics error:" << grapherrormsg(errorcode) << endl;
 187.
      cout << "Press any key to halt:";
 188.
      getch();
 189.
      exit(1); /* terminate with an error code */
 190.
      }
 191.
      max_x = getmaxx();
 192.
      max_y = getmaxy();
 193.
      }
 194.
       
 195.
      void PlaceQueen(int row, int column)
 196.
      {
 197.
      if (column == 0)/*Queen was in HOme*/
 198.
      {
 199.
      setfillstyle(SOLID_FILL, LIGHTBLUE) ;
 200.
      setcolor(LIGHTBLUE);
 201.
      pieslice(SQSIZE / 2, row * SQSIZE + SQSIZE / 2, 0, 360, 4);
 202.
      }
 203.
      delay(100);sound(400);delay(DELAY);nosound();
 204.
      setfillstyle(SOLID_FILL, BLUE) ;
 205.
      setcolor(BLUE);
 206.
      pieslice((column + 1) * SQSIZE + SQSIZE / 2, row * SQSIZE + SQSIZE / 2, 0,
 207.
      360, 4);
 208.
      }
 209.
      void RemoveQueen(int row, int column)
 210.
      {
 211.
      delay(100);sound(200);delay(DELAY);nosound();
 212.
      if (row % 2 != column % 2)
 213.
      {
 214.
      setcolor(WHITE); setfillstyle(SOLID_FILL, WHITE);
 215.
      }
 216.
      else
 217.
      {
 218.
      setcolor(YELLOW); setfillstyle(SOLID_FILL, YELLOW);
 219.
      }
 220.
      pieslice((column + 1) * SQSIZE + SQSIZE / 2, row * SQSIZE + SQSIZE / 2, 0,
 221.
      360, 4);
 222.
      }
 223.
      void HomeQueen(int row)
 224.
      {
 225.
      setfillstyle(SOLID_FILL, BLUE) ;
 226.
      setcolor(BLUE);
 227.
      pieslice(SQSIZE / 2, row * SQSIZE + SQSIZE / 2, 0, 360, 4);
 228.
      }