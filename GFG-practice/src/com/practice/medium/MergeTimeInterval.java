package com.practice.medium;

import java.util.Arrays;

class Time implements Comparable<Time> {
	int start;
	int end;

	public Time() {
	}

	public Time(int start, int end) {
		super();
		this.start = start;
		this.end = end;
	}

	@Override
	public int compareTo(Time o) {
		return this.start - o.start;
	}

	@Override
	public String toString() {
		return "[" + start + "," + end + "]";
	}

}

public class MergeTimeInterval {

	private static void mergeTime(Time[] times) {
		Arrays.sort(times);
		Time temp = new Time(times[0].start, times[0].end);
		for (int i = 0; i < times.length - 1; i++) {
			if (temp.end >= times[i + 1].start) {
				temp.end = Math.max(times[i + 1].end, temp.end);
			} else {
				System.out.print(temp + " ");
				temp.start = times[i + 1].start;
				temp.end = times[i + 1].end;
			}
		}
		System.out.println(temp);
	}

	public static void main(String[] args) {
		Time[] times = new Time[4];
		times[0] = new Time(6, 8);
		times[1] = new Time(1, 9);
		times[2] = new Time(2, 4);
		times[3] = new Time(4, 7);
		//times[4] = new Time(13, 15);

		mergeTime(times);
	}

}
