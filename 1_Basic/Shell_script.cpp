if g++ -O2 -std=c++17 -Dbbq -Wall -Wextra -Wshadow -fsanitize=address -o $1 $1.cpp; then
  echo compile success
  ./$1
else
  echo compile fail
fi
