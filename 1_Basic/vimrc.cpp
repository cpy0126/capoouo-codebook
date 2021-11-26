"This file should be placed at ~/.vimrc"
se nu ai hls et ru ic is sc cul
se re=1 ts=4 sts=4 sw=4 ls=2 mouse=a
syn on
hi cursorline cterm=none ctermbg=89
inoremap {<ENTER> {<CR>}<Esc>ko<TAB>
map <F8> <Esc>:w<CR>:!g++ "%" -o "%<" -std=c++17 -Wall
-Wextra -Wshadow -Wconversion -fsanitize=address,
undefined -g && echo success<CR>
map <F9> <Esc>:w<CR>:!g++ "%" -o "%<" -std=c++17
&& echo success<CR>
map <F10> <Esc>:!./"%<"<CR>
