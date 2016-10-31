(defun insert-header-file-contents (header-file)
  "Insert contents from a HEADER_FILE located in yasnippet snippets directory."
  (with-temp-buffer
    (insert-file-contents
      (expand-file-name header-file (car yas-snippet-dirs)))
    (buffer-string)))
