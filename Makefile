all:    r0b0tfiles done

r0b0tfiles:	
	@gcc r0b0tfiles.c -o r0b0tfiles -limobiledevice -lplist -lusb-1.0 -framework IOKit -framework CoreFoundation -framework MobileDevice -F/System/Library/PrivateFrameworks -I .
     
done:	
	@echo 'Successfully built r0b0tfiles'

clean:
	@rm -rf r0b0tfiles
	@echo Cleaned.
