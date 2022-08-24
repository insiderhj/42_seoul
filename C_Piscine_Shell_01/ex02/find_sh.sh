find . -type file -name "*.sh" -exec basename {} \; | sed "s/...$//g"
