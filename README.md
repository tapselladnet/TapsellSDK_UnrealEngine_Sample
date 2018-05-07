<div dir="rtl" align="right">
  <a href="#part2">hi</a>
  <h3>گام ۱: دریافت SDK تپسل</h3>
ابتدا فایل zip مربوط به SDK تپسل را از آدرس زیر دانلود کرده و در پوشه Plugins موجود در روت پروژه خود Extract کنید. اگر این پوشه وجود نداشت آنرا ایجاد کنید.
<p style="text-align: center;"><a href="https://storage.backtory.com/tapsell-server/sdk/tapsell-unrealengine-1.1.0.zip"><button>دریافت فایل</button></a></p>
<p style="text-align: right;">سپس برنامه را یک بار ریستارت کنید.</p>

<h3>گام ۲: دریافت کلید تپسل</h3>
وارد پنل مدیریت تپسل شده و با تعریف یک اپلیکیشن جدید با عنوان پکیج اپلیکیشن اندرویدی خود، یک کلید تپسل دریافت کنید.
<p style="text-align: center;"><a href="https://dashboard.tapsell.ir"><button>ورود به داشبورد تپسل</button></a></p>

<h3>گام ۳:تنظیمات اولیه Sdk</h3>
از منو Edit -&gt; Project Settings -&gt; Platforms -&gt; Android ، دسترسی های زیر را به پروژه اندروید خود اضافه کنید. افزودن مواردی که optional (اختیاری) هستند باعث افزایش کیفیت و بهینه بودن تبلیغات می شود که میتواند بعدا در میزان درآمد شما نیز تاثیر داشته باشند.
<pre style="direction: ltr;"><span style="color: #000080;">android.permission.ACCESS_NETWORK_STATE
android.permission.INTERNET
android.permission.READ_PHONE_STATE   (optional)
android.permission.VIBRATE   (optional)
android.permission.ACCESS_COARSE_LOCATION   (optional)
</span></pre>
&nbsp;
<h3>گام ۴: شروع کار با SDK تپسل</h3>
خطوط زیر را به انتهای فایل DefaultEngine.ini موجود در فولدر Config پروژه خود اضافه کنید:
<pre style="direction: ltr;">[Advertisement]
TapsellAppID=appKey</pre>
ورودی appKey کلید تپسلی است که در گام قبل از پنل تپسل دریافت کردید. حال از منوی

Edit -&gt; Plugins -&gt; Project -&gt; Advertising پلاگین تپسل را Enable کنید و محیط توسعه را ریستارت کنید.

پلاگین تپسل از Blueprint برای اجرا استفاده میکند. برای شروع کار با Sdk تپسل در شروع برنامه کامپوننت آنرا مانند شکل زیر اضافه کنید:
<p style="text-align: center;"><img class="size-full wp-image-2259 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/1.jpg" alt="" width="359" height="168" /></p>

</div>

