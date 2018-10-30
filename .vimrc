set ruler
set number
set linebreak
set gdefault
set hlsearch
set incsearch
set expandtab
set nowrapscan
set tabstop=2
set shiftwidth=2
set ttimeoutlen=10
hi VertSplit cterm=NONE
set fillchars+=vert:│
set showtabline=0
set background=dark
set foldmethod=syntax
set ignorecase smartcase
filetype indent on
syntax enable
cnoremap <C-S> <S-LEFT>
cnoremap <C-X> <S-RIGHT>
nnoremap <Leader>c :syntax clear<CR>
nnoremap <Leader>w i <Esc>la <Esc>h
nnoremap <Leader>s i<CR><Esc>
nnoremap <Leader>N :set number!<CR>
nnoremap <Leader>n :nohlsearch<CR>
nnoremap <Leader>O O<Esc>j
nnoremap <Leader>o o<Esc>k
nnoremap <Leader>R kddp
nnoremap <Leader>r ddpk
nnoremap <Leader>D YP
nnoremap <Leader>d Yp
nnoremap <Leader>P "_diw"0P
nnoremap <Leader>p "0p
