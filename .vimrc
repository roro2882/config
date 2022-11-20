filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'
Plugin 'habamax/vim-asciidoctor'
" python code autocomplete
Plugin 'neoclide/coc.nvim'
Plugin 'lervag/vimtex'
Plugin 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'
Plugin 'vim-autoformat/vim-autoformat'

"Ale grammar checker
"Plugin 'w0rp/ale'
"You Complete Me
"Plugin 'ycm-core/YouCompleteMe'
call vundle#end()
filetype plugin indent on

"mes bidouilles
set encoding=utf-8
autocmd FileType python map <buffer> <F9> :w<CR>:exec '!python' shellescape(@%, 1)<CR>
autocmd FileType python imap <buffer> <F9> <esc>:w<CR>:exec '!python -m pdb ' shellescape(@%, 1)<CR>
autocmd FileType tex map <buffer> <F9> :w<CR>:exec '!pdflatex % && ( chromium %:r.pdf & )'  <CR><CR>
" autocmd FileType tex map <buffer> <F9> :w<CR>:exec '!pdflatex % && ( pkill mupdf ; mupdf %:r.pdf & )'  <CR><CR>
autocmd FileType tex imap <buffer> <F9> <esc>:w<CR>:exec '!pdflatex % && ( pkill mupdf ; mupdf %:r.pdf & )' <CR><CR>

let g:vimtex_compiler_latexmk = {
        \ 'build_dir' : '',
        \ 'callback' : 1,
        \ 'continuous' : 1,
        \ 'executable' : 'latexmk',
        \ 'hooks' : [],
        \ 'options' : [
        \   '-verbose',
        \   '-file-line-error',
        \   '-synctex=1',
        \   '-interaction=nonstopmode',
	\   '-shell-escape',
        \ ],
        \}


syntax on
set autoindent    " turns it on
set smartindent   " does the right thing (mostly) in programs
set clipboard=unnamedplus
let g:vimtex_view_method = 'zathura'

let g:python3_host_prog=expand('/usr/bin/python')

" This code should go in your vimrc or init.vim
let g:UltiSnipsExpandTrigger       = '<Tab>'    " use Tab to expand snippets
let g:UltiSnipsJumpForwardTrigger  = '<Tab>'    " use Tab to move forward through tabstops
let g:UltiSnipsJumpBackwardTrigger = '<S-Tab>'  " use Shift-Tab to move backward through tabstops
let g:autoformat_autoindent = 0
let g:autoformat_retab = 0
let g:autoformat_remove_trailing_spaces = 0
 
let g:formatdef_latexindent = '"latexindent -"'

if empty(v:servername) && exists('*remote_startserver')
  call remote_startserver('VIM')
endif
