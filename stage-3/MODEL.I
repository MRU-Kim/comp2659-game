# 1 "model.c" 1
# 1 "./model.h" 1
# 1 "./../stage-2/CONST.H" 1
# 14 "./../stage-2/CONST.H"
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef int bool;
# 12 "./model.h" 2



typedef struct {
    int x, y, delta_y;
    bool isCrouched;
    bool isAlive;
    bool walkCycle;
    int runAnimationTimer;
} DinoPlayer;

typedef struct
{
    int delta_x;
} ScrollSpeed;


typedef struct {
    int x, y;
} CactusSmall;

typedef struct {
    int x, y;
} CactusMed;

typedef struct {
    int x, y;
} CactusLarge;

typedef struct {
    int y;
} Ground;

typedef struct {
    int value;
} Score;

typedef struct {
    int value;
} HighScore;

typedef struct {
    DinoPlayer player;
    CactusMed cactiMed[3];
    Ground ground;
    Score score;
    HighScore highScore;
    ScrollSpeed scrollSpeed;
    UINT16 ranNum;
    UINT16 cacSpawnTimer;

    int lastMilestone;
    UINT16 runTicksPassed;


} Model;





void dinoJump(DinoPlayer *player);
void dinoFall(DinoPlayer *player);
void dinoAirCrouch(DinoPlayer *player);
void dinoLand(DinoPlayer *player);
void dinoCrouch(DinoPlayer *player);
void dinoStand(DinoPlayer *player);
void dinoDie(DinoPlayer *player);
void dinoRunCycleAdvance(DinoPlayer *player);





void medCactusSpawn(CactusMed *cactusMed);
void medCactusScroll(CactusMed *cactusMed,ScrollSpeed scrollSpeed);


void scoreIncrement(Model *model);
void scoreReset(Score *score);


void scoreUpdate(HighScore *highScore, Score *score);


void scrollStart(ScrollSpeed *scrollSpeed);
void scrollStop(ScrollSpeed *scrollSpeed);


void modelInitialize(Model *model);
void modelResetAfterDeath(Model *model);
void modelGetSeed(Model *model);
void modelIncrmentTick(Model *model);
void modelTicksPassedReset(Model *model);
void modelResetCacSpawnTimer(Model *model);



int abs(int num);
int lfsr16(int seed);
# 18 "model.c" 2
# 1 "./../stage-2/CONST.H" 1
# 19 "model.c" 2
# 1 "C:/c68/include/time.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 10 "C:/c68/include/time.h" 2
# 26 "C:/c68/include/time.h"
typedef long 		time_t;




typedef unsigned long 		size_t;


typedef unsigned long	clock_t;

struct tm
{
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};



struct timeval {
	long	tv_sec;
	long	tv_usec;
};

struct timezone {
	int	tz_minuteswest;
	int	tz_dsttime;
};


 clock_t	clock	 (void) ;
 double		difftime (time_t, time_t) ;
 time_t		mktime	 (const struct tm *) ;
 time_t		time	 (time_t *) ;
 char * 	asctime	 (const struct tm *) ;
 char *		ctime	 (const time_t *) ;
 struct tm *	gmtime   (const time_t *) ;
 struct tm *	localtime (const time_t *) ;
 unsigned long  strftime (	char *s, size_t maxsize, const char *format, const struct tm *timeptr) ;



 void		tzset	(void) ;


 clock_t	_clock	 (void) ;
 int	gettimeofday (struct timeval *, struct timezone *) ;
 int	settimeofday (struct timeval *, struct timezone *) ;



typedef unsigned long  fd_set;


 int	select	(int, fd_set *, fd_set *, fd_set *,					struct timeval *) ;
# 25 "model.c" 2
# 32 "model.c"
void dinoJump(DinoPlayer *player)
{
    player->delta_y = -5 ;
}
# 42 "model.c"
void dinoFall(DinoPlayer *player)
{
    if (player->y < 200 -16 )
    {
        ;
        player->delta_y++;
    }
}




void dinoLand(DinoPlayer *player)
{
    player->delta_y = 0;
}




void dinoAirCrouch(DinoPlayer *player)
{
    player->delta_y = 10 ;
}





void updateDinoY(DinoPlayer *player)
{
    player->y += player->delta_y;
}





void dinoCrouch(DinoPlayer *player)
{
    player->isCrouched = 1;
}





void dinoStand(DinoPlayer *player)
{
    player->isCrouched = 0;
}





void dinoDie(DinoPlayer *player)
{
    player->isAlive = 0;
}




void dinoRunCycleAdvance(DinoPlayer *player)
{
    player->walkCycle = !player->walkCycle;
}
# 117 "model.c"
void medCactusSpawn(CactusMed *cactusMed)
{
    cactusMed->x = 640  - 1 + 16 ;
    cactusMed->y = 200 -16 ;
}
void medCactusScroll(CactusMed *cactusMed, ScrollSpeed scrollSpeed)
{
    if (cactusMed->x > -16 )
    {
        cactusMed->x -= scrollSpeed.delta_x;
    }
}
# 135 "model.c"
void scoreReset(Score *score)
{
    score->value = 0;
}
# 147 "model.c"
void scoreUpdate(HighScore *highScore, Score *score)
{
    if (score->value > highScore->value)
    {
        highScore->value = score->value;
    }
}



void scrollStart(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = 5;
}

void scrollStop(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = 0;
}
# 174 "model.c"
void modelInitialize(Model *model)
{
    int i;
    model->player.x = 100 ;
    model->player.y = 200 -16 ;
    model->player.delta_y = 0;
    model->player.isAlive = 1 ;
    model->player.isCrouched = 0 ;
    model->player.runAnimationTimer = 15 ;


    for (i = 0; i < 3; i++)
    {
        model->cactiMed[i].x = -16;
        model->cactiMed[i].y = 200 -16 ;
    }
    model->ground.y = 200 ;


    model->score.value = 0;


    model->highScore.value = 0;

    model->scrollSpeed.delta_x = 0;

    modelGetSeed(model);
    modelResetCacSpawnTimer(model);
    model->lastMilestone = 0;
    model->runTicksPassed = 0;
}




void modelResetAfterDeath(Model *model)
{
    int i;
    model->player.x = 100 ;
    model->player.y = 200 -16 ;
    model->player.delta_y = 0;
    model->player.isAlive = 1 ;
    model->player.isCrouched = 0 ;


    for (i = 0; i < 3; i++)
    {
        model->cactiMed[i].x = -16;
        model->cactiMed[i].y = 200 -16 ;
    }

    model->score.value = 0;


    model->cacSpawnTimer = ;
    model->lastMilestone = 0;
    model->runTicksPassed = 0;
}



void modelGetSeed(Model *model)
{
    model->ranNum = time(((void *)0) );
}





void modelIncrmentTick(Model *model)
{
    model->runTicksPassed++;
}




void modelTicksPassedReset(Model *model)
{
    model->runTicksPassed = 0;
}



void modelResetCacSpawnTimer(Model *model)
{
    model->ranNum = lfsr16(model->ranNum);
    model->cacSpawnTimer = abs(model->ranNum % 70) + 70;
}
# 272 "model.c"
int abs(int num)
{
    if (num < 0)
    {
        num = -num;
    }
    return num;
}
# 286 "model.c"
int lfsr16(int seed)
{
    UINT16 lfsr = seed;
    UINT16 feedback;

    feedback = (lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) & 1;
    lfsr = (lfsr >> 1) | (feedback << 15);
    return lfsr;
}
