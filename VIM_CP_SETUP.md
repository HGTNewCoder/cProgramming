# Vim for Competitive Programming: What I Set Up & How to Do It Yourself

This is a record of how Vim was customized for competitive programming (C++), written so you can
**rebuild it from scratch** and keep practicing.

Environment: Vim 8.2 (Ubuntu on WSL2), g++ 11.4, Windows Terminal.

---

## 0. Files that were created

| File | Purpose |
|---|---|
| `~/.vimrc` | Main config: settings, plugins, keymaps, compile/run |
| `~/.vim/autoload/plug.vim` | **vim-plug**, the plugin manager (one downloaded file) |
| `~/.vim/plugged/` | Where vim-plug installs plugins (one folder each) |
| `~/.vim/templates/template.cpp` | Code loaded automatically into every new `.cpp` file |
| `~/.vim/UltiSnips/cpp.snippets` | Your personal C++ snippets (`fori`, `dsu`, `powmod`...) |

> `~` means your Linux home folder (`/home/thinh`). Open the config any time with `vim ~/.vimrc`.

---

## 1. Cheat sheet (keys you'll use every day)

The **leader key is `Space`**, so `<leader>y` means press `Space` then `y`.

### Compile & run (only in `.cpp` files, normal or insert mode)
| Key | What it does |
|---|---|
| `F8` | Save + compile only (shows warnings/errors) |
| `F9` | Save + compile + run; **type the input yourself**, finish with `Ctrl-D` |
| `F10` | Save + compile + run with **`input.txt`** (same folder as the source) |
| `F7` | **Debug build**: sanitizers + checked STL, run with `input.txt`. Catches out-of-bounds, overflow, etc. |

Each run also prints how long the program took (`real 0m0.005s`).

### Editing
| Key | What it does |
|---|---|
| `(` `[` `{` `"` `'` | Auto-inserts the closing pair, cursor goes in the middle |
| `)` `]` `}` when the same char is next | Steps over it instead of doubling it |
| `Backspace` inside `()` | Deletes both brackets |
| `Enter` inside `{}` | Opens an indented block |
| `Tab` | Inserts **4 spaces** |
| `>>` / `<<` (normal), `>` / `<` (visual) | Indent / unindent by 4 spaces |
| `gcc` | Toggle comment on the current line (vim-commentary) |
| `gc` + motion, e.g. `gcip`, or `gc` in visual mode | Comment a paragraph / selection |
| `=G` from top (`gg=G`) | Re-indent the whole file |

### Snippets (UltiSnips)
Type the trigger word, then press **`Ctrl-j`**. Press `Ctrl-j` / `Ctrl-k` to jump between the fields.

| Trigger | Expands to |
|---|---|
| `fori` | `for (int i = 0; i < n; i++) { }` |
| `forr` | Reverse for loop |
| `all` | `v.begin(), v.end()` |
| `vi` | Read a `vector<int>` of size n |
| `tc` | `int t; cin >> t; while (t--) { }` |
| `dbg` | `cerr` debug print wrapped in `#ifdef LOCAL` |
| `gcd`, `powmod`, `dsu` | Ready-made functions/structs |

### Other leader shortcuts
| Key | What it does |
|---|---|
| `Space y` | Copy the **whole file to the Windows clipboard** (paste into Codeforces) |
| `Space i` | Open `input.txt` in a split on the right |
| `Space t` | Replace the current buffer with the template |
| `Space se` | Edit your snippets file for this language |
| `Space h` | Clear search highlighting |
| `Space a` | Select the whole file |
| `Space w` / `Space q` | Save / quit |
| `Ctrl-h/j/k/l` | Move between split windows |

---

## 2. Rebuild it from scratch (step by step)

Follow these steps to practice. Back up the current config first: `mv ~/.vimrc ~/.vimrc.bak`.

### Step 1: Install the plugin manager (vim-plug)
```bash
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```
Any `.vim` file in `~/.vim/autoload/` is loaded on demand. That's how `plug#begin()` becomes available.

### Step 2: Declare the plugins at the top of `~/.vimrc`
```vim
set nocompatible
let mapleader = " "

call plug#begin('~/.vim/plugged')
  Plug 'jiangmiao/auto-pairs'        " auto-close () [] {} "" ''
  Plug 'tpope/vim-commentary'        " gcc to comment
  Plug 'morhetz/gruvbox'             " colour scheme
  Plug 'itchyny/lightline.vim'       " status line
  Plug 'SirVer/ultisnips'            " snippets (needs +python3)
call plug#end()
```
Then open Vim and run **`:PlugInstall`**. `'user/repo'` is just the GitHub path.

vim-plug commands:
| Command | Does |
|---|---|
| `:PlugInstall` | Install plugins that are listed but missing |
| `:PlugUpdate` | Update all plugins |
| `:PlugClean` | Delete plugins you removed from the list |
| `:PlugStatus` | Show what is installed |

`plug#end()` also turns on `filetype plugin indent on` and `syntax on` for you.

### Step 3: Tab = 4 spaces
```vim
set tabstop=4      " a real Tab character DISPLAYS as 4 columns
set shiftwidth=4   " >>, <<, and auto-indent use 4 columns
set softtabstop=4  " pressing Tab/Backspace in insert mode moves 4 columns
set expandtab      " Tab key inserts spaces instead of a Tab character
set smarttab
set autoindent     " new line copies the previous line's indent
set cindent        " C/C++ aware indentation
set cinoptions=g0,:0,N-s,l1
```
**Check it:** type a Tab and run `:set list`. Spaces show as nothing, while a real tab would show as `^I`.
`:set nolist` turns that off again.

`cinoptions` explained: `g0` puts `public:` at column 0, `:0` keeps `case` aligned with `switch`,
`N-s` stops indenting inside `namespace`, `l1` aligns code under `case x:` correctly.

### Step 4: Autobrackets (auto-pairs plugin)
Installing it is enough. One tweak:
```vim
let g:AutoPairsMultilineClose = 0   " typing } never jumps to a } on another line
```
Toggle auto-pairs on/off temporarily: `:call AutoPairsToggle()` (handy when pasting odd code).
The plugin's default `Alt-p` shortcut often doesn't reach Vim inside a terminal.

### Step 5: Looks
```vim
set termguicolors
set background=dark
silent! colorscheme gruvbox          " silent! avoids an error before :PlugInstall
set number relativenumber cursorline showmatch scrolloff=5 mouse=a
set laststatus=2 noshowmode
let g:lightline = {'colorscheme': 'gruvbox'}
```
`relativenumber` shows how far away each line is, so you can jump with `7j` or `12k` without counting.

### Step 6: Snippets (UltiSnips)
```vim
let g:UltiSnipsExpandTrigger = '<C-j>'        " NOT Tab, so Tab stays 4 spaces
let g:UltiSnipsJumpForwardTrigger = '<C-j>'
let g:UltiSnipsJumpBackwardTrigger = '<C-k>'
let g:UltiSnipsSnippetDirectories = [$HOME . '/.vim/UltiSnips']
```
Snippet file format (`~/.vim/UltiSnips/cpp.snippets`):
```
snippet fori "for loop"
for (int ${1:i} = ${2:0}; $1 < ${3:n}; $1++) {
    $0
}
endsnippet
```
- `${1:i}` is field 1 with the default text `i`. Typing replaces it.
- A later bare `$1` mirrors whatever you typed in field 1.
- `$0` is where the cursor ends up.

### Step 7: Compile & run with F-keys
This part is custom Vimscript (no plugin), because it's the part you'll most want to change.
```vim
let g:cp_flags = '-std=c++17 -O2 -Wall -Wextra -Wshadow -DLOCAL'

function! s:Compile(flags) abort
  write
  return 'g++ ' . a:flags . ' ' . shellescape(expand('%:p'))
        \ . ' -o ' . shellescape(expand('%:p:r'))
endfunction

autocmd FileType cpp nnoremap <buffer> <F9> :call <SID>Run(g:cp_flags, '')<CR>
```
Key ideas:
- `expand('%:p')` is the full path of the current file, and `%:p:r` is the same without the extension (`/path/euclid`).
- `:!cmd` runs a shell command and shows its output.
- `autocmd FileType cpp ...` with `<buffer>` makes the mapping exist **only in C++ files**.
- `-DLOCAL` lets you write code that only runs on your machine:
  ```cpp
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ```
- The F7 debug flags `-fsanitize=address,undefined -D_GLIBCXX_DEBUG` turn silent bugs
  (`v[n]` out of range, signed overflow) into a clear error message with a line number.

### Step 8: Template for new files
```vim
autocmd BufNewFile *.cpp call s:LoadTemplate()
```
`BufNewFile` fires when you open a file that **doesn't exist yet** (`vim A.cpp`). The function reads
`~/.vim/templates/template.cpp` into the buffer and places the cursor inside `solve()`.
Edit the template file to change what every new solution starts with.

### Step 9: Copy to the Windows clipboard
This Vim is built without clipboard support (`-clipboard`), but WSL can call Windows programs:
```vim
nnoremap <silent> <leader>y :silent w !clip.exe<CR>
```
`:w !cmd` sends the buffer to a command's stdin. Here that command is `clip.exe`, the Windows clipboard.

---

## 3. Vimscript basics you'll need for future customizing

| Syntax | Meaning |
|---|---|
| `set option` / `set nooption` / `set option=value` | Change a setting. `:set option?` shows the current value |
| `let g:name = value` | Set a global variable (plugins read these for config) |
| `nnoremap` / `inoremap` / `vnoremap` | Map a key in normal / insert / visual mode (non-recursive, so always use these) |
| `nmap` / `imap` | Recursive mapping (only when the right side uses another mapping) |
| `<leader>`, `<CR>`, `<Esc>`, `<C-x>`, `<F9>` | Special key names |
| `autocmd Event pattern command` | Run a command when something happens |
| `augroup name \| autocmd! \| ... \| augroup END` | Group autocmds so re-sourcing `.vimrc` doesn't duplicate them |
| `function! s:Name() abort ... endfunction` | Script-local function. Call it from a mapping with `<SID>Name()` |
| `"` | Comment. **Never put a comment after a mapping on the same line**, because it becomes part of the mapping! |
| `\` at the start of a line | Continue the previous line |

Useful commands while experimenting:
- `:source ~/.vimrc` (or `:so %` while editing it) reloads the config without restarting.
- `:verbose nmap <F9>` shows what a key is mapped to and which file set it.
- `:verbose set tabstop?` shows the value and where it was last set.
- `:help 'tabstop'`, `:help :map`, `:help autocmd` is the built-in manual (it's very good).
- `:messages` shows errors you missed.

---

## 4. Practice exercises

1. **Change the C++ standard** to C++20: edit `g:cp_flags` (g++ 11 supports `-std=c++20`), then `:so ~/.vimrc`.
2. **Add a snippet** `pii` that expands to `pair<int, int>`. (`Space se` opens the file.)
3. **Add a snippet** for a segment tree or BFS you use often.
4. **Add a mapping** `Space o` that opens `output.txt` in a split. Hint: copy the `<leader>i` line.
5. **Make F10 also save output** to `output.txt`: in `s:Run`, append `' > output.txt'`.
6. **Add a plugin**: `Plug 'tpope/vim-surround'` → `:PlugInstall`. Then try `ysiw)` on a word.
7. **Try another colour scheme**: `Plug 'joshdick/onedark.vim'` and `colorscheme onedark`.
8. **Make Python work too**: add `autocmd FileType python nnoremap <buffer> <F9> :w<CR>:!python3 %<CR>`.
9. Remove a plugin: delete its `Plug` line, `:so ~/.vimrc`, `:PlugClean`.

---

## 5. Gotchas & troubleshooting

- **Pasting code gets extra brackets?** Windows Terminal uses "bracketed paste", so a normal
  `Ctrl-Shift-V` paste is fine. If it ever breaks, run `:set paste`, paste, then `:set nopaste`.
- **F11 does nothing**: Windows Terminal uses F11 for fullscreen. That's why the debug build is on F7.
- **Compiled binaries show up in git** (`euclid`, `sum`, ...). Add a `.gitignore` to the repo:
  ```
  *
  !*.*
  !*/
  *.exe
  ```
  This ignores files without an extension, which are the compiled programs.
- **`Ctrl-j` / `Ctrl-k`** move between windows in *normal* mode but drive snippets in *insert* mode.
  Different modes mean no conflict.
- **Error on startup after editing `.vimrc`**: run `:messages` and check the line number it reports.
- Testing a config with `vim -u somefile` starts in vi-compatible mode, which breaks `\` line
  continuations. That's why `set nocompatible` is the first line of `.vimrc`.
- **Contest machine with no plugins?** The F-key compile/run, Tab settings and template are plain
  Vimscript, so copy those sections and they work anywhere.
