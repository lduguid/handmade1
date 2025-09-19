(require 'package)
    (add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/"))
(package-initialize)

(load-theme 'solarized-light t)

(menu-bar-mode -1)

(scroll-bar-mode -1)

(tool-bar-mode -1) 

(setq inhibit-startup-screen t)

(add-to-list 'default-frame-alist '(width . 90))  ; Set default width to 90 characters
(add-to-list 'default-frame-alist '(height . 60)) ; Set default height to 60 characters

(setq make-backup-files nil) ; stop creating ~ files

(defun my-compile ()
  (interactive)
  ;; Switch to `*shell*'
  (shell)
  ;; Goto last prompt, clear old input if any, and insert new one
  (goto-char (point-max))
  (comint-kill-input)
  (insert "W:/handmade/code/build.bat")
  ;; Execute
  (comint-send-input))

(global-set-key (kbd "M-m") 'my-compile)
