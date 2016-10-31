(defun insert-header-file-contents (header-file)
  "Insert contents from a HEADER_FILE located in yasnippet snippets directory."
  (with-temp-buffer
    (insert-file-contents
      (expand-file-name header-file
                        (expand-file-name "c++-mode/online_judge/"
                                          (car yas-snippet-dirs))))
    (goto-char (point-min))
    (flush-lines "^ *#ifndef *.*_H_ *$")
    (flush-lines "^ *#define *.*_H_ *$")
    (flush-lines "^ *#include *\".*\" *$")
    (flush-lines "^ *#endif *.*_H_ *$")
    (buffer-string)))
