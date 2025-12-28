// Room:/d/welcome/regroom.c
// Updated by Lonely (08/11/2002)

#include <ansi.h>
inherit ROOM;
int do_register(string arg);

void create()
{
        set("short", "泥潭註冊室");
        set("long", "\n這裡是新玩家進行註冊的地方，請您使用指令 " HIC "register " NOR "加上你的完\n"
                    "整及真實" HIC " email " NOR "地址進行註冊。\n\n"
                    "    請務必認真註冊你的電子郵件地址，" HIR "電子郵件地址是保障你一切\n"
                    "權益的依據" NOR "，包括你密碼的丟失情況下，我們通過你註冊的信箱來確\n"
                    "認你的身份和歸還你的密碼。\n\n"

                    "現在，請輸入" HIW " reg 您的email地址\n\n" NOR);


        set("item_desc", ([
        "sign":
"\t     [1;33m有關電子郵件註冊的幾點說明[0m
[37m－－－－－－－－－－－－－－－－－－－－－－－－－－[0m
首先請你仔細檢查註冊命令裡輸入的電子郵件地址是否正確！

這個遊戲的註冊過程是由機器自動完成的，在你還沒有離開
遊戲的時候註冊信就已經發出了。如果註冊信未能正確發出
會提示你從新輸入註冊命令，只有正確發出以後才會將註冊
玩家斷線。
你收到的時間是有你的郵件服務提供者決定的，如果他們轉
信的時間快，正常情況下你應當在[1;33m10[0m秒鐘之內收到。也就是
你關上 zMud窗口打開郵件程序，就應當能收到了。最遲[1;33m1-2[0m
個小時也應當收到。
我們的遊戲給玩家留了 [1;36m48[0m 個小時的收信時間應當是很充分
的。如果在這段時間內還未能收到我們發給你的信，建議你
換一個轉信快的郵件服務提供者再次申請，或者向你的郵件
服務提供者進行諮詢。

感謝你對這個遊戲的關注。  (注：郵件註冊制度暫緩實行)
[37m－－－－－－－－－－－－－－－－－－－－－－－－－－[0m
                               \t\t[1;36m" + MUD_NAME + "巫師組[0m\n"
        ]));


        set("no_fight", 1);
        set("no_magic", 1);
        set("no_steal", 1);
        set("no_beg", 1);   
        // set("valid_startroom", 1); 
     
        setup();
}

void init()
{
        add_action("do_register", "register");
        add_action("do_register", "reg");
        add_action("do_register", "zhuce");
}

int do_register(string arg)
{
        object me = this_player();
        string mail;
        string msg;
        
        if (! arg|| strsrch(arg, "@") == -1 
        || sscanf(arg, "%*s@%*s.%*s") != 3 
        || strsrch(arg, ",") != -1)
                return notify_fail("電子郵件地址必須是 "
                                   "player@me.com 格式。\n");
        else
        {
                mail = arg;
                set("email", mail, me);

                msg=query("name", me)+"（"+query("id", me)+"）：\n\n";

                msg += "    歡迎進入泥潭的世界，從這一刻起您將有機會體驗到其他MUD 無\n" +
                       "法帶給您的快樂。\n";
                msg += "    如果您是一個喜歡聊天的人，這裡有更多，更有趣，也更全面的\n" +
                       "emote 可以讓您盡情享樂，嬉笑怒罵，完全不必負責任。\n";
                msg += "    如果您是一個喜歡練功的人，這裡的門派之間將達到最大限度的\n" +
                       "平衡，多樣的任務系統可以讓您比較順利的成就一代宗師。\n";
                msg += "    如果很不巧的您是一個利慾薰心的人，這裡的官職系統一定可以\n" +
                       "滿足您擔當兵馬大將軍的慾望。\n";
                msg += "    如果您是一個渴望生活的人，您可以在這裡娶妻生子，買房釣魚\n" +
                       "為樂，享受那一份世外高人的恬靜與淡雅。\n";
                msg += "    如果您對MUD 遊戲感到很陌生，我們的泥潭中有完善的新手指引\n" +
                       "系統，並設有專門的新人導師對各位新玩家進行指導。\n";
                msg += "    同時，這裡嚴格貫徹“公平，公正，公開”六字真言，努力為各\n" +
                       "位玩家打造一片純淨的遊戲天空。\n";
                msg += "    更多的遊戲特色您可以訪問我們的網站www.chinesemud.org，或\n" +
                       "者直接進入遊戲內部用help命令進行查詢。如果您對我們的遊戲有任\n" +
                       "何意見，您可以在遊戲內部的留言板上留言，或者直接登陸我們的論\n" +
                       "壇bbs.chinesemud.org。\n";
                msg += "    再次衷心感謝您參與我們的遊戲，在此泥潭的巫師們將以最大的\n" +
                       "熱情回報您對我們的支持。\n";
                msg += "    謝謝！\n\n";

                msg += "　　        　　　　　　　　　                泥潭巫師工作群\n";

                /*
                if (! MAIL_D->queue_mail(me, "nitan@chinesemud.org",
                        query("email", me),"感謝您光臨泥潭網絡遊戲",msg) )
                {
                        tell_object(me, query_fail_msg());
                        tell_object(me, "發送註冊郵件失敗，請註冊你正確的郵件地址！\n");
                        return 1;
                }
                */
                
                set("registered", 1, me);
                /*
                tell_object(me, "\n有一封郵件已根據您登記的地址發往\n\n" +
                                ""+HIW+query("email", me)+NOR+"\n\n請您"
                                HIG "二分鐘" NOR "後檢查您的電子郵件信箱。\n");
                */
                tell_object(me, HIR "\n祝您在泥潭玩的愉快！:)\n\n" NOR);
                message("vision", "只見白光一閃，"+me->name()+"消失了。\n", environment(me), ({me}) ); 
                // SMTP_D->send_mail(me,mail);
                me->move("/d/register/entry");
                message("vision", "你忽然發現前面多了一個人影。\n", environment(me), me);
                
                return 1;
        }
}
