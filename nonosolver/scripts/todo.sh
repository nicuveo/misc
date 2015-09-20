#! /bin/sh

IFS="
"
KEYWORD="TODO
FIXME"

kw='\033[00;31m'
fl='\033[01;34m'
end='\033[0m'

files()
{
    FILES=""

    for k in $KEYWORD ; do
	for line in `find src -type f | fgrep -v ".svn" | xargs fgrep -nH $k` ; do
	    FILES="`echo $line | sed 's/^\([^:]*\).*/\1/'` $FILES"
	done
    done

    echo "$FILES" | sed 's/ *$//' | sed 's/\([^\\]\) /\1\n/g' | sort | uniq
}

echo "Searching keywords in project source files..."

for file in `files` ; do
    echo
    echo -e "$fl$file$end"

    for k in $KEYWORD ; do
	line=`fgrep -nH $k $file`

	if [ -z "$line" ] ; then
	    continue
	fi

 	info=`echo "$line" | sed 's/[^:]*:\([^:]*\):[	 ]*\(.*\)/\1/'`
 	text=`echo "$line" | sed 's/[^:]*:[^:]*:[	 ]*\(.*\)/\1/' | sed "s/^.*$k/\\\\$kw$k\\\\$end/"`

 	echo -e "\t$info:\t$text"
    done
done
