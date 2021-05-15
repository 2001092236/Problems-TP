!/bin/bash

walk(){
	path=$1
	ext=$2
	pathdir=$3
	content=$(ls $path)
	directories=''
	ind=$4
	for file in $content
	do
		newpath=$path'/'$file
		if [ $pathdir = $newpath ]
		then
			continue
		fi
		if [ -d "$newpath" ]
		then
			directories="$directories $newpath"
		else
			if [ ${file##*.} = $ext ]
			then
				cp $newpath $pathdir'/'${file%.*}"-$ind.$ext"
				ind=$((ind + 1))
			fi
		fi
	done
	for i in $directories
	do
		walk $i $ext $pathdir $ind
	done
}

path=$1
ext=$2
dirname=$3
archname=$4

mkdir $dirname
walk $path $ext $dirname 1

tar -zcf "$archname" $dirname
echo "done"
