// This program is a part of NITAN MudLIB 
// redl 2013/6
#include <ansi.h>

#define INIT_POND 10000000              //gold
#define DATA_FILE "/u/redl/obj/cigarette.o"
int pond = INIT_POND;

int do_save(int i)
{
        if (i < INIT_POND) i = INIT_POND;
        write_file(DATA_FILE, to_string(i), 1);
        return 1;
}

int do_load()
{
        int i;
        string s;
        if (file_size(DATA_FILE)>0) {
                s = read_file(DATA_FILE);
                i = to_int(s);
        }
        else i = INIT_POND;
        //write(NOR + "i:" + to_string(i) + "\n"+ NOR); 
        return i;
}

int chk_pond(object me)
{
        int i, rnd, flag = 0;
        pond = do_load();
        //write(HIG + "start:" + to_string(pond) + "\n"+ NOR); 

        for(i = 12; i > 0; i--) {       
                rnd = random(2);
                //write(NOR + "test:" + to_string(rnd) + "\n"+ NOR); 
                if (rnd) {
                        flag += 1;
                } else
                        break;
        }
        //write(HIG + "flag:" + to_string(flag) + "\n"+ NOR); 

        if (flag >= 12) {//連中12個1
                pond /= 2;
                //write(HIY + "win:" + to_string(pond) + "\n"+ NOR); 
                addn("balance", pond * 10000, me);
                addn("cigarette_gold", pond, me); //個人累計獲獎的黃金
                log_file("static/cigarette", sprintf("(%s)%s(%s)獲得頭獎 %s 萬兩黃金。\n",  ctime(time()), me->name(), query("id", me), to_string(pond/10000))); 
                write(HIG + "小常子拱手涎臉道：恭喜恭喜，獲得獎池裡" + chinese_number(pond) + "兩黃金，打賞一點？\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "聽說" + query("name", me) + "抽菸中了頭獎，贏得了" + chinese_number(pond) + "兩的獎池黃金。\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "某人(Someone.)：你已經贏過" + chinese_number(query("cigarette_gold", me)) + "兩了吧，這是想要逆天嗎？\n" + NOR);
                do_save(pond);
                //write(HIY + "pond:" + to_string(pond) + "\n"+ NOR); 
                return 1;
        }

        if (flag >= 8) {
                //pond /= 50;
                //write(HIY + "win:" + to_string(pond) + "\n"+ NOR); 
                //addn("balance", pond * 10000, me);
                addn("balance", 10000000000, me);//改為每次100萬，不從獎池裡扣除
                //addn("cigarette_gold", pond, me); //個人累計獲獎的黃金
                addn("cigarette_gold", 1000000, me); //個人累計獲獎的黃金
                //log_file("static/cigarette", sprintf("(%s)%s(%s)獲得大獎 %s 萬兩黃金。\n",  ctime(time()), me->name(), query("id", me), to_string(pond/10000))); 
                log_file("static/cigarette", sprintf("(%s)%s(%s)獲得大獎 %s 萬兩黃金。\n",  ctime(time()), me->name(), query("id", me), to_string(1000000))); 
                //write(HIG + "小常子拱手涎臉道：恭喜恭喜，獲得獎池裡" + chinese_number(pond) + "兩黃金，打賞一點？\n" + NOR);
                write(HIG + "小常子拱手涎臉道：恭喜恭喜，獲得獎池裡" + chinese_number(1000000) + "兩黃金，打賞一點？\n" + NOR);
                //CHANNEL_D->channel_broadcast("rumor", "聽說" + query("name", me) + "抽菸中了大獎，贏得了" + chinese_number(pond) + "兩的獎池黃金。\n" + NOR);
                //CHANNEL_D->channel_broadcast("rumor", "某人(Someone.)：你已經贏過" + chinese_number(query("cigarette_gold", me)) + "兩了吧，這是狗屎運氣嗎？\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "聽說" + query("name", me) + "抽菸中了大獎，贏得了" + chinese_number(1000000) + "兩黃金。\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "某人(Someone.)：你已經贏過" + chinese_number(query("cigarette_gold", me)) + "兩了吧，這是狗屎運氣嗎？\n" + NOR);
                //pond *= 49;
                //do_save(pond);
                //write(HIY + "pond:" + to_string(pond) + "\n"+ NOR); 
                return 1;
        }

        pond += 10000;  //累積50%香菸售價
        do_save(pond);
        //write(RED + "pond:" + to_string(pond) + "\n"+ NOR); 
        return 1;
}

int ask_pond(string name)
{
        object me = this_player();
        pond = do_load();
        tell_object(me, CYN + name + "鬼鬼祟祟地告訴你：聽說獎池裡有" + chinese_number(pond) + "兩黃金，抽菸中獎可拿走部分。\n" + NOR); 
        return 1;
}



