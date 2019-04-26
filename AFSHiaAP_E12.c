#define FUSE_USE_VERSION 30
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <grp.h>
#include <pwd.h>
#include <stdlib.h>
#include <time.h>

static const char *dirpath = "/home/idputuwiprah/modul4";

char result[1000]="\0";
char resu[1000]="\0";
char chrlist[100]="qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
void decrypt(char text[1000], int key){
	int temp;
	memset(result,'\0',sizeof(result));
	for(int i=0;text[i]!= '\0';++i){
		if(text[i]=='/'){
			result[i]='/';
			continue;
		}
		for(int j=0;j<94;++j){	
			if(text[i]==chrlist[j]){	
				if(j>key){
					result[i]=chrlist[j-key];	
					j=94;
				}
				else {
					temp = 94-(key-j);
					result[i]=chrlist[temp];
					j=94;
					
				}
				
			}
			
		}		
		
	}	

}
void encrypt(char text[1000], int key){
	int temp;
	memset(resu,'\0',sizeof(resu));
	for(int i=0;text[i]!= '\0';++i){
		if(text[i]=='/'){
			resu[i]='/';
			continue;
		}
		for(int j=0;j<94;++j){
			if(text[i]==chrlist[j]){	
				if((94-j)>key)   {
					resu[i]=chrlist[j+ke];	
					j=94;
				}
				else {
					temp = key-(94-j);
					resu[i]=chrlist[temp];
					j=94;
				}
				
			}
			
		}		
		
	}
}

void* ekstension(void *arg)
{
	memset(resu,'\0',sizeof(resu));
	char *path = (char*)arg;
	if (strstr(path, "/YOUTUBER") != NULL)
	{
		while(flag==0){}
		char oldname[1100];
		char newname[1100];
		encrypt(path,17);
		sprintf(oldname, "%s%s",dirpath,resu);
		strcpy(newname,oldname);
		char ext[] = ".iz1";
		encrypt(ext,17);
		strcpy(newname+strlen(newname), ext);
		rename(oldname, newname);
	}
	return NULL;
}

static int xmp_getattr(const char *path, struct stat *stbuf)
{
  int res;
  	memset(resu,'\0',sizeof(resu));
	char fpath[1000];
	char temp[1000];
	sprintf(temp,"%s",path);
	encrypt(temp,17);
	sprintf(fpath,"%s%s",dirpath,resu);
	//printf("path apa nih: %s\n", fpath);
	res = lstat(fpath, stbuf);
	//memset(resu,'\0',sizeof(resu));
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
		       off_t offset, struct fuse_file_info *fi)
{
  char fpath[1000];
  char temp[1000];
  	strcpy(temp,path);
  	memset(resu,'\0',sizeof(resu));
  	encrypt(temp,17);
	sprintf(fpath, "%s%s",dirpath,resu);
	//encrypt(temp,17);
	int res = 0;

	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		memset(result,'\0',sizeof(result));
		memset(temp,'\0',sizeof(temp));
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
		
		char usrtarget1[20], grptarget[20], usrtarget2[20];
		char pathskrg[1000];
		gid_t gid;
		uid_t uid;

		strcpy(usrtarget1,"chipset");
		strcpy(usrtarget2,"ic_controller");
		strcpy(grptarget,"rusak");
		strcpy(pathskrg,fpath);

		strcpy(temp,de->d_name);
		strcpy(pathskrg+strlen(pathskrg),temp);
		stat(pathskrg,&st);

		gid = st.st_gid;
		uid = st.st_uid;

		struct group *grp;
		grp = getgrgid(gid);

		char grpname[20];
		strcpy(grpname, grp->gr_name);

		struct passwd *usr;
		usr = getpwuid(uid);

		char usrname[20];
		strcpy(usrname, usr->pw_name);

		if( ((strcmp(usrname,usrtarget1) == 0) || (strcmp(usrname,usrtarget2) == 0)) && (strcmp(grpname,grptarget) == 0) )
		{
			FILE *cek, *target;
			cek = fopen(pathskrg,"r");
			if(cek==NULL){
				target = fopen("/home/idputuwiprah/modul4/filemiris.txt","w");
				if(target==NULL)
				struct tm mod = *localtime(&(st.st_atime));
				char isiFIle[1100];
				sprintf(isiFIle, "%s %d %d %d:%d:%d %d-%d-%d", temp,gid,uid,mod.tm_hour,mod.tm_min,mod.tm_sec,mod.tm_mday,mod.tm_mon,mod.tm_year+1900);
				fputs(isiFIle,target);
				fclose(target);
				printf("ini isinya cuk : %s\n\n\n", isiFIle);
				remove(pathskrg);
			}
			fclose(cek);
		}

		if((strcmp(temp,".")!=0) && (strcmp(temp,"..")!=0)) {
			decrypt(temp,17);
			res = (filler(buf, result, &st, 0));
			if(res!=0) break;
		}
	}

	closedir(dp);
	return 0;
}

static int xmp_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
	memset(resu,'\0',sizeof(resu));
  	char fpath[1000];
  	char temp[1000];
	
	strcpy(temp,path);
	
	encrypt(temp,17);
	
	if(strcmp(resu,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,resu);
	}
	
	int res = 0;
  	int fd = 0 ;

	(void) fi;
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		return -errno;

	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);
	return res;
}

static int xmp_mkdir(const char *path, mode_t mode)
{
	memset(resu,'\0',sizeof(resu));
	char fpath[1000];
	char temp[1000];
	
	strcpy(temp,path);

	if (strstr(temp, "/YOUTUBER") != NULL) {
		mode = 750;
	}
	
	encrypt(temp,17);

	if(strcmp(resu,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,resu);
	}
    int res;

    res = mkdir(fpath, mode);
    if(res == -1)
        return -errno;

    return 0;
}

static int xmp_create(const char *path, mode_t mode, struct fuse_file_info *fi)
{
	memset(resu,'\0',sizeof(resu));
	char fpath[1000];
	char temp[1000];
	
	strcpy(temp,path);
	
	if (strstr(temp, "/YOUTUBER") != NULL) {
		mode = 640;
	}

	encrypt(temp,17);

	if(strcmp(resu,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,resu);
	}
	
	int fd;
	
	fd = creat(fpath, mode);
	if (fd == -1)
		return -errno;
	close(fd);
	flag = 0;
	pthread_t tid;
	pthread_create(&tid, NULL, &ekstension, fpath);

	return 0;
}

static int xmp_utimens(const char *path, const struct timespec ts[2])
{
	memset(resu,'\0',sizeof(resu));
	char fpath[1000];
	char temp[1000];
	
	strcpy(temp,path);
	
	encrypt(temp,17);
	
	if(strcmp(resu,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,resu);
	}

	int res;

	res = utimensat(0, fpath, ts, AT_SYMLINK_NOFOLLOW);
	flag = 1;
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_chmod(const char *path, mode_t mode)
{
	memset(resu,'\0',sizeof(resu));
	char fpath[1000];
	char temp[1000];
	
	strcpy(temp,path);

	int len = strlen(temp);
	if (strstr(temp, "/YOUTUBER/") != NULL && temp[len - 1] == '1' && temp[len - 2] == 'z' && temp[len - 3] == 'i' && temp[len - 4] == '.') {
    	printf("File ekstensi iz1 tidak boleh diubah permissionnya.\n");
    	return -1;
	}

	encrypt(temp,17);

	if(strcmp(temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,temp);
	}

	int res;

	res = chmod(fpath, mode);
	if (res == -1)
		return -errno;

	return 0;
}

static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.mkdir		= xmp_mkdir,
	.read		= xmp_read,
	.create     = xmp_create,
	.utimens	= xmp_utimens,
	.chmod		= xmp_chmod,
};

int main(int argc, char *argv[])
{
	umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}
