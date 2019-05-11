# NWP_myarpspoof_2018
**MITM attack via ARP spoof**

![forthebadge](https://forthebadge.com/images/badges/built-with-grammas-recipe.svg)![forthebadge](https://forthebadge.com/images/badges/60-percent-of-the-time-works-every-time.svg)

![shields.io](https://img.shields.io/badge/Docker-18.06.1-blue.svg?style=for-the-badge&logo=Docker)![shields.io](https://img.shields.io/badge/docker--compose-v1.22.0-blue.svg?style=for-the-badge)

[![Codacy Badge](https://img.shields.io/codacy/grade/dd835695f2204829995675cb9a38e645.svg?style=for-the-badge&labelColor=darkgreen&logo=Codacy)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=xNero321/nwp_mychap_2018&amp;utm_campaign=Badge_Grade)

[![CircleCI](https://circleci.com/gh/xNero321/NWP_myarpspoof_2018.svg?style=svg)](https://circleci.com/gh/xNero321/NWP_myarpspoof_2018)

## Requirement

- GNU Make 4.2.1

________________________________

## Purpose

This program is used to spoof a victim MAC address in order to receive and send his ARP packets.
It's defined as a malicious software and can cause leaks of personal information.
This project is for educational purpose only and not intended for criminal purposes.
We are not responsible for whatever you intend to use it for.
________________________________

## Usage

	USAGE: sudo ./myARPspoof <source_ip> <dest_ip> <iface>
        source_ip   your current IP address
        dest_ip     victim IP address
        iface       interface used to send/receive packets
________________________________

## Codacy analysis

This project use Codacy analysis, to see the project analysis

________________________________

## CI/CD Implementation [:WIP]

This project use CircleCI as integration software, every stages is located
in the `.circleci/config.yml` file composed of 1 stages/jobs.

PIPELINE:

- Build of the source code using EPITECH docker image

________________________________
