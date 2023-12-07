<div align="justify">

Subject translated to English: 
------------------------------

# Born2beroot

This project is an exercise in system administration. 

## General Index
I. Preamble 2  
II. Introduction 3  
III. General Instructions  
IV. Mandatory Section  
V. Bonus Section  
VI. Submission and Evaluation  

## Chapter I | Preamble 
You can do anything you want to do. Virtual Machine. This is your world. 

## Chapter II | Introduction
This project aims to introduce you to the wonderful world of virtualisation.

You will create your first machine in VirtualBox (or UTM if you cannot use VirtualBox) under specific instructions. Thus, at the end of the project, you will be able to configure your own operating system using strict rules. 

## Chapter III | General Instructions
• The use of VirtualBox is mandatory (or UTM if VirtualBox does not work on your machine).   
• You should only submit a file named signature.txt in the root of your repository. You must paste in it the signature of your machine's virtual disk. Go to Submission and Evaluation for more information.   

## Chapter IV | Mandatory Section
This project involves setting up your first server following a series of specific rules. 

As it involves configuring a server, you should install the minimum
number of services. Therefore, a graphical interface does not make
sense. Therefore, it is prohibited to install X.org or any equivalent graphical server. If you do, your grade will be 0. 

You must choose as the operating system the latest stable version of Debian (not testing/unstable), or the latest stable version of Rocky. Debian is strongly recommended if you have no experience in system administration. 

Configuring Rocky is quite complex. Therefore, you do not have to
configure KDump. However, SELinux must be run at startup
and its configuration must be adapted to the project's needs.
AppArmor in Debian must also be run at startup. 

You must create at least 2 encrypted partitions using LVM. You can find an example of what is expected. 

During the defence, you will be asked some questions about the operating
system you have chosen. Therefore, you should know the differences
between aptitude and apt, or what SELinux and AppArmor are. In short,
understand what you are using! 

The SSH service will run only on port 4242. For security, it must not be possible to connect via SSH as root. 

The use of SSH will be checked during the defence by creating a new
user. Therefore, you must understand how it works. 

You must configure your operating system with the UFW firewall (or firewalld in Rocky), leaving only port 4242 open. 

Your firewall must be active when you run the virtual machine.
For Rocky, you should use firewalld instead of UFW. 

• The hostname of your virtual machine should be your login ending in 42 (e.g., wil42). You must change this hostname during your evaluation.   
• You must implement a strong password policy.   
• You must install and configure sudo following strict rules.   
• In addition to the root user, a user with your login as name must exist.   
• This user must belong to the user42 and sudo groups.   

During the defence, you must create a user and assign it to a
group. To configure a strong password policy, you must meet the following requirements:

• Your password must expire every 30 days.   
• The minimum number of days allowed before changing a password should be
2.   
• The user must receive a warning message 7 days before their password expires.   
• Your password must be at least 10 characters long. It must contain an uppercase letter and a number. By the way, it cannot have more than 3 consecutive identical characters.  
• The password cannot contain the user's name.   
• The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the old password.   
• Obviously, your root password must follow this policy.   
 
After preparing your configuration files, you must change the
password of all accounts present in the virtual machine, including root. 

To configure a strong password for your sudo group, you must meet the following requirements:

• Authentication with sudo should be limited to three attempts in the event of entering an incorrect password.   
• A personalised message of your choice should be displayed in case the password entered is incorrect when using sudo.   
• For each command executed with sudo, both the input and output must be archived in the /var/log/sudo/ directory.   
• TTY mode must be activated for security reasons.   
• For security, the directories usable by sudo should be restricted. For example:   
     /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin   
     
Finally, you must create a simple script called monitoring.sh. It must be developed in bash.

When the server starts, the script will display certain information (listed below) on all terminals every 10 minutes (Take a look at wall). The wall banner is optional. No errors should be visible.

Your script must always show the following information:

• The architecture of your operating system and its kernel version.   
• The number of physical cores.   
• The number of virtual cores.   
• The currently available RAM on your server and its percentage of use.   
• The currently available memory on your server and its utilisation as a percentage.   
• The current percentage of use of your cores.   
• The date and time of the last restart.   
• Whether LVM is active or not.   
• The number of active connections.   
• The number of server users.   
• The IPv4 address of your server and its MAC (Media Access Control)   
• The number of commands executed with sudo.   

During the defence, you will be asked how this script works. You must
interrupt it without modifying it. Take a look at cron. 

You have two commands that you can use to check some of the subject's requirements. 

## Chapter V | Bonus Section
List of bonuses: 

• Configure the partitions correctly to obtain a structure similar to the one shown.    
• Set up a functional WordPress site with the following services: lighttpd, MariaDB, and PHP.   
• Configure a service of your choice that you consider useful (NGINX / Apache2 excluded).   

During the defence, you must justify your choice. To complete the bonus part, you have the option of configuring
additional services. In this case, you can open more ports according
to your needs. Of course, the UFW/Rocky rules must be adapted as necessary. 

The bonus part will only be evaluated if the mandatory part is
PERFECT. Perfect means that the mandatory part is entirely
functional and complete. If you have not completed ALL the mandatory part,
your bonus part will not be evaluated. 

## Chapter VI | Submission and Evaluation
You should only submit a signature.txt file in the root of your Git repository. You must paste in it the signature of your virtual disk. To obtain this signature, you must first open the default installation path (i.e., where your VMs are saved).

• Windows: %HOMEDRIVE%%HOMEPATH%\VirtualBox VMs\   
• Linux: ~/VirtualBox VMs/   
• Mac M1: ~/Library/Containers/com.utmapp.UTM/Data/Documents/ • MacOS: ~/VirtualBox VMs/   

Then retrieve the signature of the ".vdi" file (or ".qcow2" for UTM users) of your virtual machine in sha1 format. You have 4 examples of commands for a rocky_serv.vdi file: 

• Windows: certUtil -hashfile rocky_serv.vdi sha1 • Linux: sha1sum rocky_serv.vdi   
• For Mac M1: shasum rocky.utm/Images/disk-0.qcow2 • MacOS: shasum rocky_serv.vdi   

This is an example of the type of result you will get: 

• 6e657c4619944be17df3c31faa030c25e43e40af   

Please note that the signature of your VM may be altered
after your first evaluation. To solve this problem, you can
duplicate your virtual machines or use save state. 

It is obviously PROHIBITED to submit your virtual machine in your
Git repository. During the defence, the contents of the
signature.txt file will be compared with the signature of your virtual machine. If the
two are not identical, your grade will be 0.

A Student from 42 Barcelona has wriiten a great tutorial for this project, I recommend to consult his repo for details [Tutorial](https://github.com/gemartin99/Born2beroot-Tutorial). 
</div>
