
package com.android.bbtmanager;

import android.os.Bundle;
import android.os.IBinder;
import android.content.Context;
import android.os.RemoteException;
import android.util.Base64;
import android.util.Log;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.ComponentName;
import android.app.Application;
import android.app.Service;
import android.os.SystemProperties;
import android.text.format.DateFormat;

import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.Arrays;
import java.util.Calendar;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.lang.StringBuffer;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.IOException;

import android.net.Uri;

import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.util.Locale;
import java.util.Iterator;
import java.util.Map.Entry;

import android.hardware.usb.UsbDevice;
import android.hardware.usb.UsbManager;
import android.media.MediaCodecInfo;
import android.media.MediaCodecList;
import android.content.ContentResolver;
import android.os.SystemClock;

import android.database.Cursor;
import android.os.IBinder;
import android.os.ServiceManager;
public class BbtManager {
    private static final String TAG = "BbtManager";
    private final Context mContext;
    
    static {
        System.loadLibrary("bbtmanager_jni");
    }

    public BbtManager(Context context) {
        mContext = context;
    }

	public static int getTestValue(int x, int y){
		return _getTestValue(x, y);
	}
	
	public static int setLedStatus(int upEye, int downEye, int mouth, int ear){
		return _setLedStatus(upEye, downEye, mouth, ear);
	}

	private native static int _getTestValue(int x, int y);
	private native static int _setLedStatus(int a, int b, int c, int d);

}
