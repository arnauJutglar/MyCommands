# Create directories if they don't exist.
if [ ! -d ~/MyCommands ]
then
    mkdir ~/MyCommands
fi

if [ ! -d ~/MyCommands/bin ]
then
    mkdir ~/MyCommands/bin
fi

if [ ! -d ~/MyCommands/resources ]
then
    mkdir ~/MyCommands/resources
fi

# Compile the C source code.
for I in src/*.c 
do
    gcc "$I" -o "${I%.c}"
done

# Check if there is not already a program with the same name and in that case copy them to the binary commands directory.
cd bin && \
for I in *
do
    if [ -f ~/MyCommands/bin/"$I" ]
    then
        echo "A command with equal name $I is already installed."
    else
        cp "$I" ~/MyCommands/bin
    fi 
done

# Add the binaries path to ~/.bash_profile so it adds it every time a user starts its computer.
echo 'export PATH=$PATH:~/MyCommands/bin' >>~/.bash_profile
