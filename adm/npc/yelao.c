#include <ansi.h>
inherit NPC;
#include "/quest/quest4/chousha.h"
#include "/quest/quest4/place_room.h"
//#include "zuji.h"

string ask_shengsi();
string ask_zuji();
void load_killer(int num);
int killer_times;
void create()
{
    set_name("無名老人", ({ "wuming laoren", "wuming", "laoren"}));
    set("gender", "男性");
    set("age", 120);
    //set("nickname", HIW"古往今來 " HIM" 無所不知 "HIG" 笑傲江湖 "HIY" 天下無敵" NOR);
    set("nickname", HIY "王者歸來" NOR);
    set("title", HIG "笑傲江湖" NOR);
    set("long",
        "傳說中的武林前輩，據說此老乃百年前的武林宿耄，現今已百歲高齡。\n"
        "他笑傲武林數十載，天下的武功，各門各派奇聞軼事，古往今來武林\n"
        "典故，號稱是“無所不知，無所不曉”。一身武功是出神入化，罕逢\n"
        "敵手，至今數十年未曾與人動手。多年來一直隱居揚州城中評書為生，\n"
        "每日在此講述武林典故。\n");

    set("combat_exp", 15000000);
    set("shen_type", 1);
    set("max_neili", 40000);
    set("neili", 40000);
    set("max_qi",10000);
    set("max_jing",5000);
    set("max_jingli",10000);
    set("jingli",10000);
    set("per",25);
    set("jiali", 400);

    set_skill("force", 650);
    set_skill("quanzhen-jianzhen", 800);
    set_skill("array", 800);
    set_skill("quanzhen-xinfa", 700);
    // set_skill("xuanmen-neigong", 380);
    set_skill("unarmed", 700);
    set_skill("xiantian-gong", 650);
    set_skill("dodge", 700);
    // set_skill("tianshan-feidu", 360);
    set_skill("jinyan-gong", 700);
    set_skill("parry", 700);
    set_skill("jinguan-yusuo", 700);
    set_skill("strike", 700);
    set_skill("chongyang-shenzhang", 660);
    set_skill("haotian-zhang", 700);
    set_skill("finger", 700);
    set_skill("zhongnan-zhi", 660);
    set_skill("sun-finger", 700);
    // set_skill("qixing-shou", 380);
    set_skill("sword", 700);
    // set_skill("qixing-jian", 360);
    // set_skill("tonggui-jian", 360);
    set_skill("quanzhen-jian", 700);
    // set_skill("tiangang-chenfa", 340);
    set_skill("taoism", 650);
    set_skill("literate", 650);
    set_skill("huajia-su", 700);
    set_skill("martial-cognize", 650);
    set_skill("medical", 680);
    set_skill("liandan-shu", 680);
    set_skill("cuff",680);
    set_skill("whip",680);
    set_skill("chunyang-quan",680);
    set_skill("duanyun-bian",680);
    set_skill("array",650);
    set_skill("beidou-zhenfa", 650);

    map_skill("force", "xiantian-gong");
    map_skill("sword", "quanzhen-jian");
    // map_skill("whip", "tiangang-chenfa");
    map_skill("dodge", "jinyan-gong");
    map_skill("parry", "haotian-zhang");
    map_skill("unarmed", "xiantian-gong");
    map_skill("finger", "sun-finger");
    map_skill("strike", "haotian-zhang");
    // map_skill("hand", "qixing-shou");
    map_skill("cuff",   "chunyang-quan");
    map_skill("whip",   "duanyun-bian");
    prepare_skill("unarmed", "xiantian-gong");



    set("inquiry", ([
        "生死狀": (: ask_shengsi:),
        "生死"  : (: ask_shengsi :),
        //"阻擊"  : (: ask_zuji:),
    ]) );

    set("chat_chance", 10);
    set("chat_msg", ({
        CYN"無名老人捋了捋長鬚，哈哈大笑道：“張三丰那小道士，現在算起來也該有些出息了！”\n"NOR,
        CYN"無名老人輕撫掌中劍匣，無不得意地說道：“老夫縱橫江湖百餘載，還真沒遇到過對手！”\n"NOR,
        CYN"無名老人微顯扭捏之色，嘆道：“林朝英那丫頭，現在也不知道怎麼樣了。” \n"NOR,
    }));

    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.hun" :),
        (: perform_action, "unarmed.fen" :),
        (: perform_action, "unarmed.dang" :),
        (: perform_action, "unarmed.jian" :),
        (: perform_action, "parry.suo" :),
        (: exert_function, "hup" :),
        (: exert_function, "shield" :),
        (: exert_function, "recover" :),
        (: exert_function, "powerup" :),
    }));

    set("family/family_name","全真教");
    setup();

    carry_object("/d/city/npc/obj/changjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
}

void init()
{

/*
    if( interactive (ob) )
    {
        remove_call_out("story_check");
        remove_call_out("check_time");
    }

    if( !query_temp("story_start", ob) )
    {
        call_out("story_check",2);
        set_temp("story_start", 1, ob);
    }

    if( !query_temp("check_time", ob) )
    {
        call_out("check_time", 1);
        set_temp("check_time", 1, ob);
    }
*/
}


int check_time()
{
    object *ulist;
    int num,chousha_count;
    string temp;

    ulist=users();
    num=sizeof(ulist);
    num=num/2+random(num/2);
    if( num > 30 ) num=30;

    if( (time()-query("chousha_begin")) > 5400 && num>9 && !query("chousha") )
    {
        temp=read_file("/quest/quest4/chousha_count",1,1);
        chousha_count=atoi(temp);
        //if( chousha_count >= 5 && zuji_times < 1 )
/*
        if( 0 )
        {
            set("chousha_begin",time());
            temp=sprintf("%d",time());
            write_file("/quest/quest4/time_begin",temp,1);

            zuji_times=1;

            message("channel:rumor",
                MAG"【故事傳聞】少林方丈玄慈接到一封信件。\n"
                "信中寫道：契丹國有大批武士要來偷襲少林寺，想將寺中秘藏數百年的武功圖譜一舉奪去。\n"
                "玄慈大師心想：不行，要是契丹此舉成功，大宋便有亡國之禍。\n"
                "玄慈大師一看，信中還寫道：聽說這些契丹武士要道經雁門。\n"
                "玄慈大師心想：要在雁門關外迎擊，縱不能盡數將之殲滅，也要令他們的奸謀難以得逞。\n"
                "玄慈大師盤算：丐幫汪幫主，萬勝刀王維義，黃山鶴雲道長，還有一些武林朋友都可以去迎擊。\n"
                "玄慈大師盤算：但是恐怕敵人人數還是會比我們多得多，況且我們這邊武功精強者也是寥寥無幾。\n"
                "玄慈大師發愁：這可怎麼辦呢？\n"
                "玄慈大師深深地嘆了口氣。\n"
                ".........\n"
                NOR+BLINK+HIW"一場血戰即將在雁門關外展開.........\n"NOR,users());
            call_out("zuji_begin",180,num);
            call_out("zuji_close",3600);
            call_out("remove_enemy",3600);
        } else
*/
        {
            chousha_count++;
            temp=sprintf("%d",chousha_count);
            write_file("/quest/quest4/chousha_count",temp,1);

            message("channel:rumor",
                    MAG"【江湖】"NOR+
                    HIB"據說江湖中某兩大門派為解宿怨，一個時辰內要以武力解決。\n"NOR,users());
                    set("chousha_begin",time());
                    set("chousha",1);
                    temp=sprintf("%d",time());
                    write_file("/quest/quest4/time_begin",temp,1);
            call_out("chousha_begin",60);
        }
    }

    if((time()-query("chousha_begin")) > 10 && query("chousha")
        && (time()-query("chousha_begin")) < 60)
    message("channel:rumor", MAG"【江湖】"NOR+
    HIB"據可靠消息，會有兩大門派在不久以後大火拼。\n"NOR,users());
    if((time()-query("chousha_begin")) > 70 && query("chousha")
        && query("chousha")<4)
    {
        addn("chousha",1);
        message("channel:rumor", MAG"【江湖】"NOR+HIR+fam1
        +HIC"與"+HIR+fam2
        +HIC"兩大門派積怨已久，此刻正在北京城正相互仇殺。\n"NOR,users());
    }

    if( query("chousha") == 4 )
    {
            addn("chousha",1);
            load_killer(num);
    }

    remove_call_out("check_time");
    call_out("check_time",30);
    return 1;
}



void load_killer(int num)
{
    object killer1,killer2;
    int n,time,exp_rate;
    string temp;

    if( killer_times >= 4 )
    {
        killer_times=1;
        remove_call_out("load_killer");
        exp_rate=6;
        temp=sprintf("%d",exp_rate);
        write_file("/quest/quest4/exp_rate",temp,1);
        return;
    }

    killer_times++;
    for(n=0;n<num;n++)
    {
        time=query("chousha_begin")+1800-time();
        killer1=new("/quest/quest4/killer1");
        place_room("西城",killer1);
        killer2=new("/quest/quest4/killer2");
        place_room("東城",killer2);
        killer1->start_escape(time);
        killer2->start_escape(time);
    }

    remove_call_out("load_killer");
    call_out("load_killer",10,num);
    return;
}

int story_check()
{
    string *story_msg=({}),str;
    int story_msg_len;

    story_msg+= ( {"寶刀屠龍，號令武林，倚天不出，誰與爭鋒！\n"} );
    story_msg+= ( {"少林禪宗精不老，武當道學氣綿綿。\n"} );
    story_msg+= ( {"古墓創派方三代，幽居古墓潛修心。\n"
"                      銀索金鈴玄鐵劍，玉石俱焚鬼神傷。\n"} );
    story_msg+= ( {"華山自古稱劍宗，獨孤九劍傲四方。"} );
    story_msg+= ( {"桃花島主鬼谷才，奇門五行遁無影。\n"
"                      碧海潮生歌一曲，方圓百里人心慌。\n"} );
    story_msg+= ( {"日月教下盡閹黨，葵花辟邪勢莫擋。"} );
    story_msg+= ( {"先天功馭全真劍，重陽一生不輸人。"} );
    story_msg+= ( {"明教絕藝聖火令，七傷挪移妙無雙。"} );
    story_msg+= ( {"丐幫四海皆為家，露宿偷討不亦忙。\n"
"                      剛猛無敵降龍掌，精妙輕靈打狗棒。\n"} );
    story_msg+= ( {"慕容家傳盡絕藝，斗轉星移眾莫敵。\n"
"                      劍指飛揚盡隨意，光復大燕待後人。"} );
    story_msg+= ( {"星宿門下善使毒，毒掌化功魂魄寒。\n"} );
    story_msg+= ( {"峨嵋不問世俗事，靜坐參悟大乘功。\n"
"                      渡世濟人自修身，妙用無窮臨濟莊。\n"} );
    story_msg+= ( {"少林自古多絕藝，驚魔一指不尋常。\n"
"                      習盡醉棍達摩劍，三渡座下日月鞭。\n"} );
    story_msg+=( {"趙客縵胡纓，吳鉤霜雪明。\n"
"                      銀鞍照白馬，颯沓如流星；\n"
"                      十步殺一人，千里不留行；\n"
"                      事了拂衣去，深藏身與名；\n"
"                      閒過信陵飲，脫劍膝前橫；\n"
"                      將炙啖朱亥，持觴勸侯嬴；\n"
"                      三杯吐然諾，五獄倒為輕；\n"
"                      眼花耳熱後，競氣素霓生；\n"
"                      救趙揮金錘，邯鄲先震驚；\n"
"                      千秋二壯士，亙赫大梁城；\n"
"                      縱死俠骨香，不慚世上英；\n"
"                      誰能書閣下，白首太玄經。\n" });
    story_msg+= ( {"段家絕藝非尋常，六脈劍成天下驚。\n "
"                     十年鐵杵磨成針，仗劍江湖自在行。\n"});
    story_msg+= ( {"飛雪連天射白鹿，笑書神俠倚碧鴛。\n "});
    story_msg+= ( {"少室山頭琴未冷，風陵渡口似聞聲。\n "
"                     人間自有情難老，不信嬌女白髮生。\n"});
    story_msg+= ( {"白馬未馱夕照去，西風已送傷心來。\n "
"                     中原可有英雄淚，為洗秋蘭帶露開。\n"});
    story_msg+= ( {"靈樞終未得天樞，素問何曾問髯鬍。\n "
"                     燭淚滴殘海棠冷，忍聽山歌到曉無？\n"});
    story_msg+= ( {"漫唱採茶覺已遲，猶憐深信未相欺。\n "
"                     世間多少痴情女，傷盡男兒不自知。\n"});
    story_msg+= ( {"燕子塢前從此醉，杏花林裡向來痴。\n "
"                     紅顏老去英雄在，落日牛羊歸去遲。\n"});
    story_msg+= ( {"倦世何由惜此身，楊郎履下漫多塵。\n "
"                     人間自有花如雨，妾是花中第幾人？ \n"});
    story_msg+= ( {"萬騎卻回千騎分，中原何計御胡塵？\n "
"                     世間一死寧無懼？君為家山我為君。\n"});
    story_msg+= ( {"來如流水逝如風，何處來兮何所終。\n "
"                     滄海茫茫掛帆去，天涯從此各西東。\n"});
    story_msg+= ( {"風中弱絮蕩輕盈，贏得世間傾國名。\n "
"                     昨日江山今夜月，琵琶一曲唱生平。\n"});
    story_msg+= ( {"平生至樂在何處，平生至愛是何人？\n "
"                     一醉千杯君莫問，憐取姑射山中人。\n"});
    story_msg+= ({ "發現BUG請報告巫師，可以獲得適當獎勵。\n"
"                      隱瞞並利用BUG獲利的，給予懲罰，甚至殺檔處理。\n" });
    story_msg+=({"江湖自古多浩劫，殺機一現屍成野。\n"
"                      勸君未到功力老，勿動妄思問生死。\n"});


    story_msg_len=sizeof(story_msg);
    str=story_msg[random(story_msg_len)];

    message("channel:mess",sprintf(HIY"\n【典故】無名老人：%s\n" NOR, str),users());
    remove_call_out("story_check");
    call_out("story_check",300);
}

// 玩家之間的戰鬥獎勵要寫在這裡set_override("die", func)
string ask_shengsi()
{
    object me;
    string fam1,fam2,temp;
    int exp_rate,exp;
    me=this_player();

    if( query_temp("chousha/ask", me) )
        return CYN"你現在已經加入江湖了，你的敵對門派是"+query_temp("chousha/fam",me)+"趕快去吧！\n"NOR;

    if( query("chousha")<2 )
        return CYN"仇殺還沒正式開始呢，先等一會吧！\n"NOR;

    if( query("chousha")>3 )
        return CYN"你來太遲了，趕不上這次仇殺了，等下次吧！\n"NOR;

    if( query("combat_exp",me)<1000000 )
        return CYN"憑你現在這點本事，不相干的事還是不要多管的好！\n"NOR;

    if( query("score", me)<1000 )
        return CYN"你在江湖中的聲望太低了，估計沒有哪個門派會邀請你！\n"NOR;

    exp=query("combat_exp",me);
    temp=read_file("/quest/quest4/exp_rate",1,1);
    exp_rate=atoi(temp);
    if( !wizardp(me) && (exp_rate*exp_rate/4) < exp/100000 )
    {
        do{
            exp_rate++;
        } while( (exp_rate*exp_rate/4) < exp/100000 );

        temp=sprintf("%d",exp_rate);
        write_file("/quest/quest4/exp_rate",temp,1);
    }

    fam1=read_file("/quest/quest4/fam1",1,1);
    fam2=read_file("/quest/quest4/fam2",1,1);

    if( query_temp("chousha/fam",me) )
    {
        set_temp("chousha/ask",1,me);
        command("chat "+query("name",me)+"加入江湖對付"+query_temp("chousha/fam",me)+"，生死由命，立狀為憑！\n");

        if( query_temp("chousha/fam",me)==fam2 )
        {
            set_temp("apply/short",
                    ({HIW+fam1+"同道"NOR+HIG"   江湖義士   "NOR+query("name",me)+"("+query("id",me)+")"}),me);
        }
        else if( query_temp("chousha/fam",me)==fam1 )
        {
            set_temp("apply/short",
                    ({CYN+fam2+"助拳"NOR+HIG"   江湖豪客   "NOR+query("name",me)+"("+query("id",me)+")"}),me);
        }

        call_out("heading_for",1,me);
        return CYN"你立刻前往京城加入此次江湖，一切好自為之了！\n"NOR;
    }

    if( query("shen",me) >= 200000 || (query("shen",me) > -200000 && random(2)) )
    {
        set_temp("chousha/fam",fam2,me);
        delete_temp("apply/short",me);
        set_temp("apply/short",
                ({HIW+fam1+"同道"NOR+HIG"   江湖義士   "NOR+query("name",me)+"("+query("id",me)+")"}),me);
        command("chat "+query("name",me)+"加入江湖對付"+fam2+"，生死由命，立狀為憑！\n");
    } else
    {
        set_temp("chousha/fam",fam1,me);
        delete_temp("apply/short",me);
        set_temp("apply/short",
                ({CYN+fam2+"助拳"NOR+HIG"   江湖豪客   "NOR+query("name",me)+"("+query("id",me)+")"}),me);
        command("chat"+query("name", me)+"加入江湖對付"+fam1+"，生死由命，立狀為憑！\n");
    }

    set_temp("chousha/ask",1,me);
    call_out("heading_for",1,me);
    return CYN"你立刻前往北京加入此次江湖，一切好自為之了！\n"NOR;
}


/*
string ask_zuji()
{
    object me;
    int exp_rate,exp;
    string temp;

    me=this_player();
    if( query_temp("zuji/ask", me) )
    return CYN"你現在已經加入阻擊契丹武士了，趕快去吧！\n"NOR;

    if( zuji_times < 1 )
    return CYN"現在江湖上好好的，你居心何在啊？！\n"NOR;

    if( zuji_times > 1 )
    return CYN"江湖英雄令發完了，正在準備中，你等會吧！\n"NOR;

    if( query("combat_exp", me)<1000000 )
    return CYN"你還是先學好本領再來吧！\n"NOR;

    if( query("score", me)<1000 )
    return CYN"你在江湖中的聲望太低了，江湖英雄令你接不起啊！\n"NOR;

    exp=query("combat_exp", me);
    temp=read_file("/quest/quest4/killer_rate",1,1);
    exp_rate=atoi(temp);
    if( !wizardp(me) && (exp_rate*exp_rate/4) < exp/100000 )
    {
            do{
                  exp_rate++;
              } while( (exp_rate*exp_rate/4) < exp/100000 );

              temp=sprintf("%d",exp_rate);
              write_file("/quest/quest4/killer_rate",temp,1);
    }

    command("chat"+query("name", me)+"接下了"+HIW"江湖英雄令"
            +HIC"，對抗此次契丹武士，江湖各路同道共勉！\n");

    me->delte_temp("apply/short");
    me->set_temp("apply/short",
          ({HIR"英雄令使"NOR+me->name()+"("+query("id", me)+")"}));
    set_temp("zuji/ask", 1, me);

    return CYN"呵呵，又是一個不怕死的，武林有望啊，多加小心吧！\n"NOR;
}
*/


int heading_for(object me)
{
    string fam1,fam2;

    fam1=read_file("/quest/quest4/fam1",1,1);
    fam2=read_file("/quest/quest4/fam2",1,1);

    if( objectp(me) && query_temp("chousha/fam",me) )
    {
        if( query_temp("chousha/fam",me) == fam2 )
            me->move("/maze/jingcheng/juyi");
        else if( query_temp("chousha/fam",me) == fam1 )
            me->move("/maze/jingcheng/yingxiong");
    }
    message_vision(YEL"$N一路馬不停蹄，連夜趕到了紫金城！\n"NOR,me);
    return 1;
}
