#	Environment  
CentOS 7.4  
Subversion 1.10  
#	References  
Subversion Download Website:   
https://www.aliyun.com/jiaocheng/141813.html  
Configuration Reference Website:   
https://wiki.centos.org/HowTos/Subversion  
Permission Problem:  
https://serverfault.com/questions/625579/svn-cant-open-file-var-www-svn-repo-db-txn-current-lock-permission-denied  

# Configuration  
## step1: Installation Packages  
\# yum install mod_dav_svn subversion  

## step2: apache  
\# systemctl start httpd  
\# chkconfig httpd on

## step3: Subversion’s apache configurations
```javascript
# vim /etc/httpd/conf.d/subversion.conf
# Make sure you uncomment the following if they are commented out    
LoadModule dav_svn_module     modules/mod_dav_svn.so
LoadModule authz_svn_module   modules/mod_authz_svn.so`

\# Add the following to allow a basic authentication and point Apache to where the actual
\# repository resides.  
<Location /human>  
        DAV svn  
        SVNPath /var/www/svn/human  
        AuthType Basic  
        AuthName "Subversion repos"  
        AuthUserFile /etc/svn-auth-conf  
        Require valid-user    
</Location>

## step4: add user
# htpasswd -cm /etc/svn-auth-conf yourusername
New password:
Re-type new password:
Adding password for user yourusername
```

## step5: Configure your repository  
```
# cd /var/ww
# mkdir svn
# cd svn
# svnadmin create human
# chown -R apache.apache human
# setsebool -P httpd_unified=1			//close selinux
# systemctl restart httpd
```
 
# 问题汇总
* 1	发现服务器无法连接?  
问题分析：这种情况可能是由于服务的的防火墙开启，导致远程访问被屏蔽，因此需要关闭防火墙和selinux  
解决方案：  
//close firewall
\# systemctl stop firewalld.service  
\# systemctl disable firewalld.service  
\# vim /etc/selinux/config  //disable selinux  
\# reboot


* 2.问题2  
 




