(defun insert-header-file-contents (header-file)
  "Insert contents from a HEADER_FILE located in yasnippet snippets directory."
  (with-temp-buffer
    (insert-char ?\n)
    (insert-file-contents
      (expand-file-name header-file
                        (expand-file-name "c++-mode/online_judge/"
                                          (car yas-snippet-dirs))))
    (goto-char (point-min))
    (while (re-search-forward "^[[:space:]]*#[[:space:]]*include[[:space:]]+\"\\(.+\\)\"[[:space:]]*\\(?://.*\\)?$" nil t)
	    (unless (string-equal (match-string 1) "main.h")
        (replace-match (insert-header-file-contents (match-string 1)))))
    (buffer-string)))
